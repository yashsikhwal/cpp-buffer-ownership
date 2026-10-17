# cpp-buffer-ownership

A C++17 learning project demonstrating RAII, resource ownership, and the Rule of Five.

## Features

- Dynamically sized integer storage owned by `std::unique_ptr<int[]>`
- Deep-copy construction and copy assignment
- Move construction and move assignment
- Resource swapping
- A runnable demonstration and focused ownership tests

## Build and run

Requirements: CMake 3.16 or later and a C++17 compiler.

```sh
cmake -S . -B build
cmake --build build
./build/buffer_lab
```

Run the tests with:

```sh
ctest --test-dir build --output-on-failure
```

To build and run the tests with AddressSanitizer and UndefinedBehaviorSanitizer:

```sh
cmake -S . -B build-sanitized -DENABLE_SANITIZERS=ON
cmake --build build-sanitized
ctest --test-dir build-sanitized --output-on-failure
```
