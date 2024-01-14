set(PROJECT LiquidCrystal_pico)

cmake_minimum_required(VERSION 3.13)

# set(PICO_BOARD "pico_w")

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(${PROJECT} C CXX)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Adding includes
include_directories(include)

# rest of your project
add_executable(${PROJECT} example.cpp LiquidCrystal_pico.cpp)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(${PROJECT} pico_stdlib hardware_gpio)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(${PROJECT})
