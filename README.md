# C++ Buffer Ownership

A C++17 project exploring dynamic memory management, RAII, deep copying, move semantics, and the Rule of Five.

The project implements a `Buffer` class that owns a dynamically allocated integer array using a unique pointer. It demonstrates how to manage resource ownership safely through copy and move operations.

## Features

- **RAII:** Automatic resource cleanup through `std::unique_ptr<int[]>`.
- **Deep Copy:** Independent memory allocation when copying a buffer.
- **Move Semantics:** Efficient ownership transfer without copying array elements.
- **Copy Assignment:** Replaces existing contents with an independent copy.
- **Move Assignment:** Transfers ownership and releases the destination's previous allocation.
- **Swap:** Exchanges buffer contents and ownership without allocating new arrays.
- **Self-Assignment Safety:** Handles self-copy and self-move assignment.
- **Empty Buffer Support:** Supports zero-sized buffers and a defined empty state for moved-from objects.
- **CMake Build System:** Configurable and reproducible builds using CMake.
- **Memory-Safety Checks:** Supports AddressSanitizer and UndefinedBehaviorSanitizer when enabled in the build configuration.

## Concepts Demonstrated

### Resource Acquisition Is Initialization (RAII)

The `Buffer` class uses `std::unique_ptr<int[]>` to manage the lifetime of its dynamically allocated array. When the owning object is destroyed, the array is released automatically.

### Copy Semantics

Copy construction and copy assignment perform a deep copy. The destination receives its own allocation, so modifying one buffer does not affect the other.

### Move Semantics

Move construction and move assignment transfer ownership of the existing allocation. The array does not need to be duplicated, and the moved-from object is left in a valid empty state.

### Rule of Five

```text
cpp-buffer-ownership/
├── CMakeLists.txt
├── README.md
├── .gitignore
├── include/
│   └── buffer.hpp
└── src/
    └── main.cpp
```

The exact directory names should match the structure in the repository.

## Prerequisites

- C++17-compatible compiler, such as GCC or Clang
- CMake 3.16 or later
