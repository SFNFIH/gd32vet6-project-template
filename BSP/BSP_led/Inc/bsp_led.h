#ifndef BSP_LED_H
#define BSP_LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef enum {
    BSP_LED1 = 0,
    BSP_LED_COUNT
} bsp_led_t;

void bsp_led_init(void);
void bsp_led_on(bsp_led_t led);
void bsp_led_off(bsp_led_t led);
void bsp_led_toggle(bsp_led_t led);

#ifdef __cplusplus
}
#endif

#endif /* BSP_LED_H */
