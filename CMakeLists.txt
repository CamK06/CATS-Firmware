# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.14)

# Include build functions from Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

add_definitions("-DUSBD_VID=0xdead")
add_definitions("-DUSBD_PID=0xbeef")
add_definitions("-DUSBD_PRODUCT=\"CATS Transceiver\"")
add_definitions("-DUSBD_MANUFACTURER=\"VE3KCN\"")
add_definitions("-DPICO_ENTER_USB_BOOT_ON_EXIT=1")

# Set name of project (as PROJECT_NAME) and C/C   standards
project(catsbase C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()

file(GLOB SOURCE src/*.c src/drivers/**/*.c)

# Tell CMake where to find the executable source file
add_executable(${PROJECT_NAME} 
    ${SOURCE}
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})
pico_set_linker_script(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/memmap_2040.ld)

set(Rust_CARGO_TARGET "thumbv6m-none-eabi")
add_subdirectory(libCATS)
add_subdirectory(thirdparty/lwgps)

# Ensure tinyusb can see tusb_config.h
target_include_directories(catsbase PUBLIC src libCATS/include thirdparty/lwgps/lwgps/src/include)
target_include_directories(catsbase PUBLIC src)

# Link to pico_stdlib (gpio, time, etc. functions)
target_link_libraries(${PROJECT_NAME} 
    PUBLIC pico_stdlib pico_unique_id hardware_flash hardware_sync hardware_irq hardware_spi hardware_gpio CATS lwgps
    #PUBLIC pico_stdlib pico_unique_id hardware_flash hardware_sync hardware_irq hardware_spi hardware_gpio
)

# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

include(version.cmake)
include_directories(${CMAKE_BINARY_DIR})
configure_file("${CMAKE_SOURCE_DIR}/src/version.h.in" "${CMAKE_BINARY_DIR}/version.h" @ONLY)