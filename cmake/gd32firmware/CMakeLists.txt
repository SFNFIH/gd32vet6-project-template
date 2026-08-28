cmake_minimum_required(VERSION 3.22)

# GD32VET6 Project Template firmware configuration

set(GD32_Defines_Syms
    USE_STDPERIPH_DRIVER
    GD32E50X
    GD32E50X_HD
    $<$<CONFIG:Debug>:DEBUG>
)

set(GD32_Include_Dirs
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/CMSIS/GD/GD32E50x/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Include
)

set(GD32_Application_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/gd32e50x_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/systick.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/system_gd32e50x.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/syscalls.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Core/Src/sysmem.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../startup_gd32vet6.s
)

set(GD32_Drivers_Src
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_bkp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_can.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_cmp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_crc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_ctc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_dac.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_dbg.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_enet.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_exmc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_exti.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_fmc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_fwdgt.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_misc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_pmu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_rcu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_rtc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_sdio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_shrtimer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_sqpi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_timer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_tmu.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_usart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/../../Drivers/GD32E50x_standard_peripheral/Source/gd32e50x_wwdgt.c
)

set(GD32_LINKER_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/../../GD32VET6_FLASH.ld)

set(GD32_LINK_LIBS
    GD32_Drivers
    ${TOOLCHAIN_LINK_LIBRARIES}
)

set(GD32_COMPILE_OPTIONS
    -mcpu=cortex-m33
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -mthumb
    -std=gnu11
    -fstack-usage
    -fdata-sections
    -ffunction-sections
    -fsigned-char
    -Wall
    -Wno-missing-braces
    -Wno-format
    -Wno-strict-aliasing
    $<$<CONFIG:Debug>:-g3 -O0>
    $<$<NOT:$<CONFIG:Debug>>:-g0 -Os>
)

set(GD32_LINK_OPTIONS
    -mcpu=cortex-m33
    -mfpu=fpv5-sp-d16
    -mfloat-abi=hard
    -mthumb
    -static
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--gc-sections
    -Wl,--start-group -lc -lm -Wl,--end-group
)

add_library(gd32firmware INTERFACE)
target_include_directories(gd32firmware INTERFACE ${GD32_Include_Dirs})
target_compile_definitions(gd32firmware INTERFACE ${GD32_Defines_Syms})
target_compile_options(gd32firmware INTERFACE ${GD32_COMPILE_OPTIONS})
target_link_options(gd32firmware INTERFACE ${GD32_LINK_OPTIONS})

add_library(GD32_Drivers OBJECT)
target_sources(GD32_Drivers PRIVATE ${GD32_Drivers_Src})
target_link_libraries(GD32_Drivers PUBLIC gd32firmware)

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${GD32_Application_Src})

target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    -T${GD32_LINKER_SCRIPT}
    -Wl,-Map=${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.map
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${GD32_LINK_LIBS})

if((CMAKE_C_STANDARD EQUAL 90) OR (CMAKE_C_STANDARD EQUAL 99))
    message(FATAL_ERROR "Generated code requires C11 or higher")
endif()
