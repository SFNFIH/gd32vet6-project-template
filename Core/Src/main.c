/*!
    \file    main.c
    \brief   GD32VET6 Project Template application
*/

#include "main.h"
#include "bsp.h"
#include "bsp_led.h"
#include "systick.h"
#include <stdio.h>

void Error_Handler(void)
{
    while (1) {
    }
}

int main(void)
{
    systick_config();
    bsp_init();

    printf("\r\nGD32VET6 Project Template\r\n");
    printf("BSP LED and USART initialized.\r\n");

    while (1) {
        bsp_led_on(BSP_LED1);
        printf("LED1 ON\r\n");
        delay_1ms(500);

        bsp_led_off(BSP_LED1);
        printf("LED1 OFF\r\n");
        delay_1ms(500);
    }
}
