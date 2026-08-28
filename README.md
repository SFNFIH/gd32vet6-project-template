# GD32E503VET6 CMake 工程

适用于 **GD32E503VET6**（Arm Cortex-M33，512KB Flash，128KB SRAM，LQFP100）的 GCC 交叉编译 CMake 工程模板。

## 依赖

- CMake >= 3.20
- Ninja（推荐）或 Make
- `gcc-arm-none-eabi` 工具链

Ubuntu/Debian 安装示例：

```bash
sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi cmake ninja-build
```

## 构建

```bash
cmake --preset Debug
cmake --build --preset Debug
```

或使用 Release 配置：

```bash
cmake --preset Release
cmake --build --preset Release
```

构建产物位于 `build/Debug/` 或 `build/Release/`：

- `gd32e503vet6.elf` — 调试固件
- `gd32e503vet6.hex` — Intel HEX，用于烧录
- `gd32e503vet6.bin` — 二进制镜像

## 工程结构

```
.
├── Application/          # 应用代码
│   ├── Core/             # main、中断、系统初始化
│   ├── Startup/          # 启动文件与向量表
│   └── User/             # newlib 系统调用桩
├── Drivers/              # GigaDevice 官方固件库
├── cmake/                # 工具链与 MCU 配置
├── linker/               # 链接脚本
└── CMakeLists.txt
```

## MCU 配置

| 参数 | 值 |
|------|-----|
| 芯片 | GD32E503VET6 |
| 内核 | Cortex-M33 + FPU |
| Flash | 512 KB @ 0x08000000 |
| SRAM | 128 KB @ 0x20000000 |
| 系统时钟 | 180 MHz（HXTAL + PLL，见 `system_gd32e50x.c`） |
| 宏定义 | `GD32E50X`、`GD32E50X_HD`、`USE_STDPERIPH_DRIVER` |

## 自定义工具链路径

若 `arm-none-eabi-gcc` 不在 PATH 中，可在配置时指定前缀：

```bash
cmake --preset Debug -DTOOLCHAIN_PREFIX=/path/to/bin/arm-none-eabi-
```

## 烧录与调试

可使用 OpenOCD、J-Link 等工具烧录生成的 `.hex` 或 `.elf` 文件。具体连接方式取决于你的调试器与目标板硬件设计。
