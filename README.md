# GD32VET6 Project Template

GCC cross-compilation CMake project for **GD32E503VET6**, with a directory layout inspired by STM32CubeMX generated CMake projects.

## Requirements

- CMake >= 3.22
- Ninja (recommended)
- `gcc-arm-none-eabi` toolchain

```bash
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi cmake ninja-build
```

## Build

```bash
cmake --preset Debug
cmake --build --preset Debug
```

Build artifacts are written to `build/Debug/`:

- `gd32vet6_project_template.elf`
- `gd32vet6_project_template.hex`
- `gd32vet6_project_template.bin`

## Directory Layout

```
.
├── CMakeLists.txt              # User-editable root CMake file
├── CMakePresets.json
├── cmake/
│   ├── gcc-arm-none-eabi.cmake # Toolchain configuration
│   └── gd32firmware/
│       └── CMakeLists.txt      # Firmware/library configuration
├── Core/
│   ├── Inc/                    # Application headers
│   └── Src/                    # Application sources (main, interrupts, syscalls, etc.)
├── BSP/
│   ├── Inc/bsp.h               # Unified BSP init
│   ├── Src/bsp.c
│   ├── BSP_led/                # LED driver (PE4)
│   └── BSP_usart/              # USART0 driver + printf retarget
├── Drivers/
│   ├── CMSIS/
│   └── GD32E50x_standard_peripheral/
├── startup_gd32vet6.s            # Startup file
└── GD32VET6_FLASH.ld             # Linker script
```

## CubeMX Layout Mapping

| STM32CubeMX | This Project |
|-------------|--------------|
| `cmake/gcc-arm-none-eabi.cmake` | Same name |
| `cmake/stm32cubemx/CMakeLists.txt` | `cmake/gd32firmware/CMakeLists.txt` |
| `stm32cubemx` INTERFACE library | `gd32firmware` INTERFACE library |
| `STM32_Drivers` OBJECT library | `GD32_Drivers` OBJECT library |
| `Core/Inc`, `Core/Src` | Same layout |
| `startup_*.s`, `*.ld` at project root | `startup_gd32vet6.s`, `GD32VET6_FLASH.ld` |

## MCU Configuration

| Parameter | Value |
|-----------|-------|
| MCU | GD32E503VET6 |
| Core | Cortex-M33 + FPU |
| Flash / SRAM | 512 KB / 128 KB |
| Defines | `GD32E50X`, `GD32E50X_HD`, `USE_STDPERIPH_DRIVER` |

## Customization

- Add user libraries, macros, and link options in the root `CMakeLists.txt`
- Manage sources, drivers, and the linker script in `cmake/gd32firmware/CMakeLists.txt`
- Place application code in `Core/Inc` and `Core/Src`
- Board support packages live under `BSP/` (`BSP_led`, `BSP_usart`, etc.)

## BSP Pin Mapping (Schematic)

| Peripheral | Pin | Notes |
|------------|-----|-------|
| LED1 | PE4 | Active high (only MCU-controlled LED) |
| USART0 TX | PA9 | 115200 baud |
| USART0 RX | PA10 | printf via `__io_putchar` |
