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

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/time.h>
#include <time.h>

#include "qcloud_iot_import.h"

char *HAL_Timer_current(char *time_str)
{
    if (time_str == NULL)
        return " ";

    struct timeval tv;
    gettimeofday(&tv, NULL);
    time_t now_time = tv.tv_sec;

    struct tm tm_tmp = *localtime(&now_time);
    strftime(time_str, TIME_FORMAT_STR_LEN, "%F %T", &tm_tmp);

    return time_str;
}

long HAL_Timer_current_sec(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec;
}

#ifdef __cplusplus
}
#endif
