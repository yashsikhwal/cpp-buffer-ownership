#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>

class Buffer {
public:
    Buffer() noexcept = default;
    explicit Buffer(std::size_t size);
    Buffer(std::initializer_list<int> values);
    Buffer(const Buffer& other);
    Buffer(Buffer&& other) noexcept;
    Buffer& operator=(const Buffer& other);
    Buffer& operator=(Buffer&& other) noexcept;
    ~Buffer() = default;

    void swap(Buffer& other) noexcept;

    std::size_t size() const noexcept;
    bool empty() const noexcept;
    int* data() noexcept;
    const int* data() const noexcept;
    int& operator[](std::size_t index) noexcept;
    const int& operator[](std::size_t index) const noexcept;

private:
    std::unique_ptr<int[]> data_;
    std::size_t size_ = 0;
};

void swap(Buffer& lhs, Buffer& rhs) noexcept;
