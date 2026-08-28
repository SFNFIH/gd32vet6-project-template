/*!
    \file    main.c
    \brief   GD32VET6 Project Template application
*/

#include "main.h"
#include "bsp.h"
#include "bsp_led.h"
#include "systick.h"
#include <stdio.h>

#define LED_BLINK_MS    500U

void Error_Handler(void)
{
    while (1) {
    }
}

int main(void)
{
    systick_config();
    bsp_init();

    printf("\r\nGD32VET6 Project Template ready.\r\n");

    while (1) {
        bsp_led_toggle();
        delay_1ms(LED_BLINK_MS);
    }
}
