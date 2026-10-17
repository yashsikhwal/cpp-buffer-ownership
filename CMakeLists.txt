cmake_minimum_required(VERSION 3.16)

project(BufferLab VERSION 1.0 LANGUAGES CXX)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(buffer_lab
    src/main.cpp
)

target_include_directories(buffer_lab PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_compile_options(buffer_lab PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
