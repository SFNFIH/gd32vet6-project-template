# GD32VET6 工程模板

适用于 **GD32E503VET6** 的 GCC 交叉编译 CMake 工程，目录结构参考 STM32CubeMX 生成的 CMake 工程布局。

## 依赖环境

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

构建产物位于 `build/Debug/`：

- `gd32vet6_project_template.elf`
- `gd32vet6_project_template.hex`
- `gd32vet6_project_template.bin`

## 目录结构

```
.
├── CMakeLists.txt              # 用户可修改的根 CMake 文件
├── CMakePresets.json
├── cmake/
│   ├── gcc-arm-none-eabi.cmake # 工具链配置
│   └── gd32firmware/
│       └── CMakeLists.txt      # 固件库/源文件配置
├── Core/
│   ├── Inc/                    # 应用头文件
│   └── Src/                    # 应用源文件（main、中断、syscalls 等）
├── BSP/
│   ├── Inc/bsp.h               # 统一 BSP 初始化
│   ├── Src/bsp.c
│   ├── BSP_led/                # LED 驱动（PE4）
│   └── BSP_usart/              # USART0 驱动 + printf 重定向
├── Drivers/
│   ├── CMSIS/
│   └── GD32E50x_standard_peripheral/
├── startup_gd32vet6.s            # 启动文件
└── GD32VET6_FLASH.ld             # 链接脚本
```

## 与 CubeMX 目录对应关系

| STM32CubeMX | 本工程 |
|-------------|--------|
| `cmake/gcc-arm-none-eabi.cmake` | 同名 |
| `cmake/stm32cubemx/CMakeLists.txt` | `cmake/gd32firmware/CMakeLists.txt` |
| `stm32cubemx` INTERFACE 库 | `gd32firmware` INTERFACE 库 |
| `STM32_Drivers` OBJECT 库 | `GD32_Drivers` OBJECT 库 |
| `Core/Inc`、`Core/Src` | 同名 |
| 根目录 `startup_*.s`、`*.ld` | `startup_gd32vet6.s`、`GD32VET6_FLASH.ld` |

## MCU 配置

| 参数 | 值 |
|------|-----|
| 芯片 | GD32E503VET6 |
| 内核 | Cortex-M33 + FPU |
| Flash / SRAM | 512 KB / 128 KB |
| 宏定义 | `GD32E50X`、`GD32E50X_HD`、`USE_STDPERIPH_DRIVER` |

## 自定义说明

- 在根目录 `CMakeLists.txt` 中添加用户库、宏定义和链接选项
- 在 `cmake/gd32firmware/CMakeLists.txt` 中管理源文件、驱动和链接脚本
- 应用代码放在 `Core/Inc` 和 `Core/Src`
- 板级支持包位于 `BSP/`（`BSP_led`、`BSP_usart` 等）

## BSP 引脚映射（原理图）

| 外设 | 引脚 | 说明 |
|------|------|------|
| LED1 | PE4 | 高电平点亮（唯一由 MCU 控制的 LED） |
| USART0 TX | PA9 | 115200 波特率 |
| USART0 RX | PA10 | printf 通过 `__io_putchar` 重定向 |
