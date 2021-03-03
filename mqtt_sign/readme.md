## 介绍
本示例提供了设备端接入腾讯云物联网平台的 MQTT 连接参数生成的代码。

## 示例编译
修改 make.settings 替换为目标编译工具：
```
PLATFORM_CC                 	= gcc
PLATFORM_AR                 	= ar
```
然后执行 make

## 示例运行
编译完成后，生成可执行文件在 output 目录下。
./output/qcloud-mqtt-sign product_id device_name device_secret
程序生成的 Client ID username password 用于连接腾讯云物联网平台。

$ ./output/qcloud-mqtt-sign  L4WG9V9M2M TEST2 XXXXe65nKPk0Lx+ZThaA==
device_secret base64 decode:0xx 0xxx 0xxx 0xxx 0xd7 0xba 0xe6 0x72 0x8f 0x93 0x42 0xf1 0xf9 0x94 0xe1 0x68
username sign: 9ed5ea5710f9e585426dcf19e0c8c2d6af484f06
Client ID：L4WG9V9M2MTEST2
username: L4WG9V9M2MTEST2;21010406;5AiF2;92233720368547758
password: 9ed5ea5710f9e585426dcf19e0c8c2d6af484f06;hmacsha1

## 代码介绍

device_secret 为 psk 通过 base64 编码生成的，使用 `qcloud_iot_utils_base64decode` 解码出 psk。

Client ID 格式为 `productdevicename` 拼接的字符串。

username 格式为  `productdevicename;appid;randomconnid;timestamp` 拼接的字符串，其中 appid 见代码中宏 `QCLOUD_IOT_DEVICE_SDK_APPID`，randomconnid 为随机产生的字符串 ID，timestamp 为 UTC 时间戳，若系统时间戳不准确可使用 `LONG_MAX` 的值。

password 格式为 `username_sign;hmacsha1` 拼接的字符串。签名通过 `utils_hmac_sha1` 函数生成。

## 相关链接

[MQTT 接入](https://cloud.tencent.com/document/product/634/32546)