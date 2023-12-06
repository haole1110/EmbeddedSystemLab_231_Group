#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

#define TIMER1_INTERVAL 2000 // 2 seconds
#define TIMER2_INTERVAL 3000 // 3 seconds

#define TIMER1_REPEAT_COUNT 10
#define TIMER2_REPEAT_COUNT 5

TimerHandle_t timer1, timer2;
int count1 = 0, count2 = 0;

void timer_callback(TimerHandle_t xTimer) {
    if (xTimer == timer1) {
        printf("ahihi\n");
        count1++;
        if (count1 >= TIMER1_REPEAT_COUNT) {
            xTimerStop(timer1, portMAX_DELAY);
            printf("Timer 1 stopped\n");
        }
    } else if (xTimer == timer2) {
        printf("ihaha\n");
        count2++;
        if (count2 >= TIMER2_REPEAT_COUNT) {
            xTimerStop(timer2, portMAX_DELAY);
            printf("Timer 2 stopped\n");
        }
    }
}

void app_main() {
        printf("RESET BUTTON WAS PRESSED!!!\n");
    timer1 = xTimerCreate("Timer1", TIMER1_INTERVAL / portTICK_PERIOD_MS, pdTRUE, (void *)0, timer_callback);
    printf("Timer 1 was created\n");
    timer2 = xTimerCreate("Timer2", TIMER2_INTERVAL / portTICK_PERIOD_MS, pdTRUE, (void *)0, timer_callback);
    printf("Timer 2 was created\n");

    if (timer1 == NULL || timer2 == NULL) {
        printf("Failed to create timers\n");
    } else {
        xTimerStart(timer1, portMAX_DELAY);
        xTimerStart(timer2, portMAX_DELAY);
    }
}