#include "bsp_led.h"
#include "gd32e50x.h"

/* Schematic: LED1 on PE4 */
#define BSP_LED1_GPIO_PORT    GPIOE
#define BSP_LED1_GPIO_CLK     RCU_GPIOE
#define BSP_LED1_GPIO_PIN     GPIO_PIN_4

static uint32_t bsp_led_port[BSP_LED_COUNT] = {
    BSP_LED1_GPIO_PORT,
};

static uint32_t bsp_led_pin[BSP_LED_COUNT] = {
    BSP_LED1_GPIO_PIN,
};

static rcu_periph_enum bsp_led_clk[BSP_LED_COUNT] = {
    BSP_LED1_GPIO_CLK,
};

void bsp_led_init(void)
{
    for (uint32_t i = 0; i < BSP_LED_COUNT; i++) {
        rcu_periph_clock_enable(bsp_led_clk[i]);
        gpio_init(bsp_led_port[i], GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, bsp_led_pin[i]);
        gpio_bit_reset(bsp_led_port[i], bsp_led_pin[i]);
    }
}

void bsp_led_on(bsp_led_t led)
{
    gpio_bit_set(bsp_led_port[led], bsp_led_pin[led]);
}

void bsp_led_off(bsp_led_t led)
{
    gpio_bit_reset(bsp_led_port[led], bsp_led_pin[led]);
}

void bsp_led_toggle(bsp_led_t led)
{
    gpio_bit_write(bsp_led_port[led], bsp_led_pin[led],
                   (bit_status)(1U - gpio_input_bit_get(bsp_led_port[led], bsp_led_pin[led])));
}
