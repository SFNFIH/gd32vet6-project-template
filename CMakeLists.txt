cmake_minimum_required(VERSION 3.20)

include(${CMAKE_SOURCE_DIR}/cmake/gd32e503vet6.cmake)

project(gd32e503vet6 LANGUAGES C CXX ASM)

set(DRIVERS_DIR ${CMAKE_SOURCE_DIR}/Drivers)

add_subdirectory(Application)
add_subdirectory(Drivers/CMSIS)
add_subdirectory(Drivers/GD32E50x_standard_peripheral)

gd32e503vet6_add_target_properties(gd32e503vet6)
gd32e503vet6_add_target_properties(GD32E50x_standard_peripheral)
