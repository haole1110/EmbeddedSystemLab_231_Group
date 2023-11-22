/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "freertos/queue.h"

#include <time.h>



// Define the number of functional tasks
#define NUM_FUNCTIONAL_TASKS 3

TaskHandle_t functionalTaskHandles[NUM_FUNCTIONAL_TASKS];
QueueHandle_t requestQueue;

int count = 0;
int countID_task = 0;

// Structure to represent a request
typedef struct {
    int taskID;
} Request;

void receptionTask(void *pvParameters) {
    while (1) {
        // Simulate receiving a request from somewhere
        Request receivedRequest;
        receivedRequest.taskID = countID_task;
        countID_task = (countID_task + 1) % (NUM_FUNCTIONAL_TASKS + 1);

        xQueueSend(requestQueue, &receivedRequest, portMAX_DELAY);

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void functionalTask(void *pvParameters) {
    int taskID = *((int *)pvParameters);

    while (1) {
        Request nextRequest;
        if (count >= 3){
            xQueueReceive(requestQueue, &nextRequest, portMAX_DELAY);
            count = 0;
        }
        // Check if the next request is for this task
        if (xQueuePeek(requestQueue, &nextRequest, portMAX_DELAY) == pdPASS) {
            if (nextRequest.taskID == taskID) {
                xQueueReceive(requestQueue, &nextRequest, portMAX_DELAY);
                printf("RequestID: %d, Task %d: Request received and handled\n", nextRequest.taskID, taskID);
                count = 0;
            }
            else {
                printf("RequestID: %d, Task %d: Request received but not for me\n", nextRequest.taskID, taskID);
                count++;
            }
        }
        else {
            printf("Task %d: Error receiving request\n", taskID);
        }
         vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main() {
    // Create the request queue
    requestQueue = xQueueCreate(10, sizeof(Request));

    // Create the reception task
    xTaskCreate(receptionTask, "Reception Task", 2048, NULL, 1, NULL);

    // Create the functional tasks
    for (int i = 0; i < NUM_FUNCTIONAL_TASKS; i++) {
        int *taskID = malloc(sizeof(int));
        *taskID = i;
        xTaskCreate(functionalTask, "Functional Task", 2048, taskID, 2, &functionalTaskHandles[i]);
    }
}
