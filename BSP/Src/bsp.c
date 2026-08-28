#include "bsp.h"
#include "bsp_led.h"
#include "bsp_usart.h"

void bsp_init(void)
{
    bsp_led_init();
    bsp_usart_init();
}
