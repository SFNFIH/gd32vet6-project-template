#include "bsp_usart.h"
#include "gd32e50x.h"

/* Schematic: USART0 on PA9 (TX) / PA10 (RX) */
#define BSP_USART0_PERIPH       USART0
#define BSP_USART0_CLK          RCU_USART0
#define BSP_USART0_GPIO_PORT    GPIOA
#define BSP_USART0_GPIO_CLK     RCU_GPIOA
#define BSP_USART0_TX_PIN       GPIO_PIN_9
#define BSP_USART0_RX_PIN       GPIO_PIN_10

void bsp_usart_init(void)
{
    rcu_periph_clock_enable(BSP_USART0_GPIO_CLK);
    rcu_periph_clock_enable(BSP_USART0_CLK);

    gpio_init(BSP_USART0_GPIO_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, BSP_USART0_TX_PIN);
    gpio_init(BSP_USART0_GPIO_PORT, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, BSP_USART0_RX_PIN);

    usart_deinit(BSP_USART0_PERIPH);
    usart_word_length_set(BSP_USART0_PERIPH, USART_WL_8BIT);
    usart_stop_bit_set(BSP_USART0_PERIPH, USART_STB_1BIT);
    usart_parity_config(BSP_USART0_PERIPH, USART_PM_NONE);
    usart_baudrate_set(BSP_USART0_PERIPH, BSP_USART0_BAUDRATE);
    usart_receive_config(BSP_USART0_PERIPH, USART_RECEIVE_ENABLE);
    usart_transmit_config(BSP_USART0_PERIPH, USART_TRANSMIT_ENABLE);
    usart_enable(BSP_USART0_PERIPH);
}

void bsp_usart_send_byte(uint8_t data)
{
    usart_data_transmit(BSP_USART0_PERIPH, data);
    while (RESET == usart_flag_get(BSP_USART0_PERIPH, USART_FLAG_TBE)) {
    }
}

void bsp_usart_send_string(const char *str)
{
    while (*str != '\0') {
        bsp_usart_send_byte((uint8_t)*str++);
    }
}

#ifdef __GNUC__
int __io_putchar(int ch)
{
    bsp_usart_send_byte((uint8_t)ch);
    return ch;
}

int __io_getchar(void)
{
    while (RESET == usart_flag_get(BSP_USART0_PERIPH, USART_FLAG_RBNE)) {
    }

    return (int)usart_data_receive(BSP_USART0_PERIPH);
}
#endif /* __GNUC__ */
