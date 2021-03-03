/*
 * Tencent is pleased to support the open source community by making IoT Hub available.
 * Copyright (C) 2018-2020 THL A29 Limited, a Tencent company. All rights reserved.

 * Licensed under the MIT License (the "License"); you may not use this file except in
 * compliance with the License. You may obtain a copy of the License at
 * http://opensource.org/licenses/MIT

 * Unless required by applicable law or agreed to in writing, software distributed under the License is
 * distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef QCLOUD_IOT_IMPORT_H_
#define QCLOUD_IOT_IMPORT_H_
#if defined(__cplusplus)
extern "C" {
#endif

#include <inttypes.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Max size of base64 encoded PSK = 64, after decode: 64/4*3 = 48*/
#define DECODE_PSK_LENGTH 48

/* MAX valid time when connect to MQTT server. 0: always valid */
/* Use this only if the device has accurate UTC time. Otherwise, set to 0 */
#define MAX_ACCESS_EXPIRE_TIMEOUT (0)

/* Max size of conn Id  */
#define MAX_CONN_ID_LEN (6)

/* IoT C-SDK APPID */
#define QCLOUD_IOT_DEVICE_SDK_APPID "21010406"
#define QCLOUD_IOT_DEVICE_SDK_APPID_LEN (sizeof(QCLOUD_IOT_DEVICE_SDK_APPID) - 1)

#define _IN_ /* indicate an input parameter */
#define _OU_ /* indicate a output parameter */

#define QCLOUD_ERR_FAILURE  -1
#define TIME_FORMAT_STR_LEN (20)
/* log print/upload related variables */
/* MAX size of log buffer for one log item including header and content */
#define MAX_LOG_MSG_LEN (511)
#if defined(__linux__)
#undef MAX_LOG_MSG_LEN
#define MAX_LOG_MSG_LEN (1023)
#endif

/**
 * @brief Generate log for print/upload, call LogMessageHandler if defined
 *
 * When LOG_UPLOAD is enabled, the log will be uploaded to cloud server
 *
 * @param file
 * @param func
 * @param line
 * @param level
 */
void IOT_Log_Gen(const char *file, const char *func, const int line, const int level, const char *fmt, ...);

/**
 * SDK log print/upload level
 */
typedef enum { eLOG_DISABLE = 0, eLOG_ERROR = 1, eLOG_WARN = 2, eLOG_INFO = 3, eLOG_DEBUG = 4 } LOG_LEVEL;
/* Simple APIs for log generation in different level */
#define Log_d(fmt, ...) IOT_Log_Gen(__FILE__, __FUNCTION__, __LINE__, eLOG_DEBUG, fmt, ##__VA_ARGS__)
#define Log_i(fmt, ...) IOT_Log_Gen(__FILE__, __FUNCTION__, __LINE__, eLOG_INFO, fmt, ##__VA_ARGS__)
#define Log_w(fmt, ...) IOT_Log_Gen(__FILE__, __FUNCTION__, __LINE__, eLOG_WARN, fmt, ##__VA_ARGS__)
#define Log_e(fmt, ...) IOT_Log_Gen(__FILE__, __FUNCTION__, __LINE__, eLOG_ERROR, fmt, ##__VA_ARGS__)


/**
 * @brief Malloc memory
 *
 * @param size   Expected memory size (unit: byte)
 * @return       pointer to the memory
 */
void *HAL_Malloc(_IN_ uint32_t size);

/**
 * @brief Free memory
 *
 * @param ptr   pointer to the pre-malloc memory
 */
void HAL_Free(_IN_ void *ptr);

/**
 * @brief Print data to console in format
 *
 * @param fmt   print format
 * @param ...   variable number of arguments
 */
void HAL_Printf(_IN_ const char *fmt, ...);

/**
 * @brief Print data to string in format
 *
 * @param str   destination string
 * @param len   Max size of the output
 * @param fmt   print format
 * @param ...   variable number of arguments
 * @return      number of bytes that print successfull
 */
int HAL_Snprintf(_IN_ char *str, const int len, const char *fmt, ...);

/**
 Print data to string in format
  *
  * @param str   destination string
  * @param len   Max size of the output
  * @param fmt   print format
  * @param ap    arguments list
  * @return      number of bytes that print successfull

 */
int HAL_Vsnprintf(_OU_ char *str, _IN_ const int len, _IN_ const char *fmt, _IN_ va_list ap);

/**
 * @brief Get timestamp in millisecond
 *
 * @return   timestamp in millisecond
 */
uint32_t HAL_GetTimeMs(void);

/**
 * @brief Get timestamp in second
 *
 * @return   timestamp in second
 */
long HAL_Timer_current_sec(void);

/**
 * @brief Get local time in format: %y-%m-%d %H:%M:%S
 *
 * @return string of formatted time
 */
char *HAL_Timer_current(char *time_str);

#if defined(__cplusplus)
}
#endif
#endif /* QCLOUD_IOT_IMPORT_H_ */
