# GD32E503VET6: Cortex-M33, 512KB Flash, 128KB SRAM, LQFP100

function(gd32e503vet6_add_target_properties TARGET_NAME)
    target_compile_definitions(${TARGET_NAME} PRIVATE
        "$<$<CONFIG:Debug>:DEBUG>"
        "$<$<NOT:$<CONFIG:Debug>>:RELEASE>"
        GD32E50X
        GD32E50X_HD
        USE_STDPERIPH_DRIVER
    )

    target_compile_options(${TARGET_NAME} PRIVATE
        "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:ASM>>:-g3>"
        "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-g3>"
        "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-g3>"
        "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:ASM>>:-g0>"
        "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-g0>"
        "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-g0>"

        "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:C>>:-O0>"
        "$<$<AND:$<CONFIG:Debug>,$<COMPILE_LANGUAGE:CXX>>:-O0>"
        "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:C>>:-Os>"
        "$<$<AND:$<NOT:$<CONFIG:Debug>>,$<COMPILE_LANGUAGE:CXX>>:-Os>"

        -mcpu=cortex-m33
        -mfpu=fpv5-sp-d16
        -mfloat-abi=hard
    )

    target_link_options(${TARGET_NAME} PRIVATE
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

    target_link_libraries(${TARGET_NAME} PRIVATE m)
endfunction()
