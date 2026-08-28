#ifndef BSP_USART_H
#define BSP_USART_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#define BSP_USART0_BAUDRATE    115200U

void bsp_usart_init(void);
void bsp_usart_send_byte(uint8_t data);
void bsp_usart_send_string(const char *str);

#ifdef __cplusplus
}
#endif

#endif /* BSP_USART_H */
