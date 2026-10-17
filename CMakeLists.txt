cmake_minimum_required(VERSION 3.16)
project(cpp_buffer_ownership LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)
if(ENABLE_SANITIZERS)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
        add_link_options(-fsanitize=address,undefined)
    else()
        message(FATAL_ERROR "ENABLE_SANITIZERS requires GCC or Clang")
    endif()
endif()

add_library(buffer_ownership src/buffer.cpp)
target_include_directories(buffer_ownership PUBLIC include)

add_executable(buffer_lab src/main.cpp)
target_link_libraries(buffer_lab PRIVATE buffer_ownership)

include(CTest)
if(BUILD_TESTING)
    add_executable(buffer_tests tests/buffer_tests.cpp)
    target_link_libraries(buffer_tests PRIVATE buffer_ownership)
    add_test(NAME buffer_tests COMMAND buffer_tests)
endif()
