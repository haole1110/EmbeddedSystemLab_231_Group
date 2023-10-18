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
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO GPIO_NUM_12
static uint8_t state_led = 0;


void task1(void *pvParameters) {
    while (1){
        printf("Student Identifier: 2011142 \n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void task2(void *pvParameters) {
    gpio_reset_pin(GPIO_NUM_12);
    gpio_set_direction(GPIO_NUM_12 , GPIO_MODE_OUTPUT);

    gpio_reset_pin(GPIO_NUM_13);
    gpio_set_direction(GPIO_NUM_13 , GPIO_MODE_INPUT);
    gpio_set_pull_mode (13 , GPIO_PULLUP_ONLY);

    while (1) {
        // Đọc trạng thái của nút
        int buttonState = gpio_get_level(GPIO_NUM_13);

        // Kiểm tra nếu nút được nhấn (đầu ra LOW - do sử dụng pull-up)
        if (buttonState == 1) {
            // In ra "ESP32" lên Serial Monitor
            state_led = !state_led;
            gpio_set_level(GPIO_NUM_12, state_led);
            vTaskDelay(1000 / portTICK_PERIOD_MS);  // Chờ 1 giây để tránh in liên tục khi nút được giữ
        }

        // Chờ 10ms trước khi quét lại
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void app_main(void) {

    xTaskCreate(task1, "Task 1", 2048, NULL, 1, NULL);
    xTaskCreate(task2, "Task 2", 2048, NULL, 1, NULL);


}