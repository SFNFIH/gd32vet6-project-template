add_library(bsp OBJECT
    Src/bsp.c
    BSP_led/Src/bsp_led.c
    BSP_usart/Src/bsp_usart.c
)

target_include_directories(bsp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP_led/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/BSP_usart/Inc
)

target_link_libraries(bsp PUBLIC gd32firmware)
