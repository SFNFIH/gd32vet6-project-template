/*!
    \file    main.c
    \brief   GD32E503VET6 CMake template application
*/

#include "gd32e50x.h"
#include "systick.h"

int main(void)
{
    systick_config();

    /* Add your application code here */

    while (1) {
        __WFI();
    }
}
