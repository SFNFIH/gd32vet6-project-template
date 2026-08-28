#include "bsp_led.h"
#include "gd32e50x.h"

/* Schematic: LED1 on PE4 (LED3/LED4 are power-driven, not MCU-controlled) */
#define BSP_LED_GPIO_PORT    GPIOE
#define BSP_LED_GPIO_CLK     RCU_GPIOE
#define BSP_LED_GPIO_PIN     GPIO_PIN_4

void bsp_led_init(void)
{
    rcu_periph_clock_enable(BSP_LED_GPIO_CLK);
    gpio_init(BSP_LED_GPIO_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, BSP_LED_GPIO_PIN);
    gpio_bit_reset(BSP_LED_GPIO_PORT, BSP_LED_GPIO_PIN);
}

void bsp_led_on(void)
{
    gpio_bit_set(BSP_LED_GPIO_PORT, BSP_LED_GPIO_PIN);
}

void bsp_led_off(void)
{
    gpio_bit_reset(BSP_LED_GPIO_PORT, BSP_LED_GPIO_PIN);
}

void bsp_led_toggle(void)
{
    gpio_bit_write(BSP_LED_GPIO_PORT, BSP_LED_GPIO_PIN,
                   (bit_status)(1U - gpio_input_bit_get(BSP_LED_GPIO_PORT, BSP_LED_GPIO_PIN)));
}
