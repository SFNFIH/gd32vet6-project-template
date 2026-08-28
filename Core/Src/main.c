/*!
    \file    main.c
    \brief   GD32E503VET6 CMake template application
*/

#include "main.h"
#include "gd32e50x.h"
#include "systick.h"

void Error_Handler(void)
{
    while (1) {
    }
}

int main(void)
{
    systick_config();

    /* Add your application code here */

    while (1) {
        __WFI();
    }
}
