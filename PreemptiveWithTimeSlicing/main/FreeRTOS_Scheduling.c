// /*
//  * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
//  *
//  * SPDX-License-Identifier: CC0-1.0
//  */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include <time.h>


//Config this define in FreeRTOSConfig.h

//#define configUSE_PREEMPTION                         1
//#define configUSE_TIME_SLICING                       1

#define CORE_TO_USE             0
#define TASK1_PRIORITY    (tskIDLE_PRIORITY + 1)
#define TASK2_PRIORITY    (tskIDLE_PRIORITY + 1)



int i;

// Khai báo các hàm nhiệm vụ
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

int app_main(void) {
    
    // Khởi tạo FreeRTOS
    xTaskCreatePinnedToCore(vTask1, "Task 1", 4096, NULL, TASK1_PRIORITY, NULL, CORE_TO_USE);
    xTaskCreatePinnedToCore(vTask2, "Task 2", 4096, NULL, TASK2_PRIORITY, NULL, CORE_TO_USE);

    return 0;
}

void vTask1(void *pvParameters) {
    while (1) {
        // Nhiệm vụ 1
        printf("Task 1 is running...\n");
        for (i = 0; i <= 50000000; i++){
            if (i % 500000 == 0) {
                printf("Task 1: %d / 100 ...\n", i / 500000);
                //printf("Task 1: running ...\n");
            }
        }
        printf("Task 1 have completed!\n");
        //printf("Task 1 is running\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void vTask2(void *pvParameters) {
    while (1) {
        vTaskDelay(5000 / portTICK_PERIOD_MS);
        // Nhiệm vụ 2
        printf("Task 2 is running\n");
        for (i = 0; i <= 50000000; i++){
            if (i % 500000 == 0) {
                printf("Task 2: %d / 100 ...\n", i / 500000);
                //printf("Task 2: running ...\n");
            }
        }
        printf("Task 2 have completed!\n");
    }
}
















