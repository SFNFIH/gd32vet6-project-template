# GD32E503VET6 CMake 工程

适用于 **GD32E503VET6** 的 GCC 交叉编译工程，目录结构对齐 **STM32CubeMX** 生成的 CMake 工程。

## 依赖

- CMake >= 3.22
- Ninja（推荐）
- `gcc-arm-none-eabi` 工具链

```bash
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi cmake ninja-build
```

## 构建

```bash
cmake --preset Debug
cmake --build --preset Debug
```

产物位于 `build/Debug/`：

- `gd32e503vet6.elf`
- `gd32e503vet6.hex`
- `gd32e503vet6.bin`

## 目录结构（对齐 STM32CubeMX）

```
.
├── CMakeLists.txt              # 用户可修改的根 CMake 文件
├── CMakePresets.json
├── cmake/
│   ├── gcc-arm-none-eabi.cmake # 工具链配置
│   └── stm32cubemx/
│       └── CMakeLists.txt      # 固件库/源文件配置（对应 CubeMX 生成文件）
├── Core/
│   ├── Inc/                    # 应用头文件
│   └── Src/                    # 应用源文件（main、中断、syscalls 等）
├── Drivers/
│   ├── CMSIS/
│   └── GD32E50x_standard_peripheral/
├── startup_gd32e503vet6.s        # 启动文件
└── GD32E503VET6_FLASH.ld         # 链接脚本
```

## MCU 配置

| 参数 | 值 |
|------|-----|
| 芯片 | GD32E503VET6 |
| 内核 | Cortex-M33 + FPU |
| Flash / SRAM | 512 KB / 128 KB |
| 宏定义 | `GD32E50X`、`GD32E50X_HD`、`USE_STDPERIPH_DRIVER` |

## 自定义说明

- 在根目录 `CMakeLists.txt` 中添加用户库、宏定义和链接选项
- 在 `cmake/stm32cubemx/CMakeLists.txt` 中管理源文件、驱动和链接脚本（对应 CubeMX 重新生成区域）
- 应用代码放在 `Core/Inc` 与 `Core/Src`
