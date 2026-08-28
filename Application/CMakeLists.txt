add_executable(gd32e503vet6)

target_sources(gd32e503vet6 PRIVATE
    Core/Src/gd32e50x_it.c
    Core/Src/main.c
    Core/Src/systick.c
    Core/Src/system_gd32e50x.c
    Startup/startup_gd32e50x.s
    User/syscalls.c
)

target_include_directories(gd32e503vet6 PRIVATE
    ${CMAKE_SOURCE_DIR}/Application/Core/Inc
)

target_link_options(gd32e503vet6 PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker/gd32e503vet6_flash.ld
    -L${CMAKE_SOURCE_DIR}/linker
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/gd32e503vet6.map
)

target_link_libraries(gd32e503vet6 PRIVATE
    CMSIS
    GD32E50x_standard_peripheral
)

add_custom_command(TARGET gd32e503vet6 POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:gd32e503vet6> ${CMAKE_CURRENT_BINARY_DIR}/gd32e503vet6.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:gd32e503vet6> ${CMAKE_CURRENT_BINARY_DIR}/gd32e503vet6.bin
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:gd32e503vet6>
    COMMENT "Generating gd32e503vet6.hex and gd32e503vet6.bin"
)
