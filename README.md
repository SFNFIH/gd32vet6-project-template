# GD32VET6 Project Template

GCC cross-compilation CMake project for **GD32E503VET6**, with a directory layout aligned to **STM32CubeMX** generated CMake projects.

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

## Directory Layout (STM32CubeMX-style)

```
.
├── CMakeLists.txt              # User-editable root CMake file
├── CMakePresets.json
├── cmake/
│   ├── gcc-arm-none-eabi.cmake # Toolchain configuration
│   └── stm32cubemx/
│       └── CMakeLists.txt      # Firmware/library configuration (CubeMX-generated equivalent)
├── Core/
│   ├── Inc/                    # Application headers
│   └── Src/                    # Application sources (main, interrupts, syscalls, etc.)
├── Drivers/
│   ├── CMSIS/
│   └── GD32E50x_standard_peripheral/
├── startup_gd32vet6.s            # Startup file
└── GD32VET6_FLASH.ld             # Linker script
```

## MCU Configuration

| Parameter | Value |
|-----------|-------|
| MCU | GD32E503VET6 |
| Core | Cortex-M33 + FPU |
| Flash / SRAM | 512 KB / 128 KB |
| Defines | `GD32E50X`, `GD32E50X_HD`, `USE_STDPERIPH_DRIVER` |

## Customization

- Add user libraries, macros, and link options in the root `CMakeLists.txt`
- Manage sources, drivers, and the linker script in `cmake/stm32cubemx/CMakeLists.txt` (CubeMX regeneration equivalent)
- Place application code in `Core/Inc` and `Core/Src`
