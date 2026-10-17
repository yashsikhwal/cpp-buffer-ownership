#include "buffer.hpp"

#include <algorithm>
#include <utility>

Buffer::Buffer(std::size_t size)
    : data_(size == 0 ? nullptr : std::make_unique<int[]>(size)), size_(size) {}

Buffer::Buffer(std::initializer_list<int> values)
    : Buffer(values.size()) {
    if (values.size() != 0) {
        std::copy(values.begin(), values.end(), data_.get());
    }
}

Buffer::Buffer(const Buffer& other)
    : Buffer(other.size_) {
    if (size_ != 0) {
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
}

Buffer::Buffer(Buffer&& other) noexcept
    : data_(std::move(other.data_)), size_(std::exchange(other.size_, 0)) {}

Buffer& Buffer::operator=(const Buffer& other) {
    if (this != &other) {
        Buffer copy(other);
        swap(copy);
    }
    return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    if (this != &other) {
        data_ = std::move(other.data_);
        size_ = std::exchange(other.size_, 0);
    }
    return *this;
}

void Buffer::swap(Buffer& other) noexcept {
    data_.swap(other.data_);
    std::swap(size_, other.size_);
}

std::size_t Buffer::size() const noexcept {
    return size_;
}

bool Buffer::empty() const noexcept {
    return size_ == 0;
}

int* Buffer::data() noexcept {
    return data_.get();
}

const int* Buffer::data() const noexcept {
    return data_.get();
}

int& Buffer::operator[](std::size_t index) noexcept {
    return data_[index];
}

const int& Buffer::operator[](std::size_t index) const noexcept {
    return data_[index];
}

void swap(Buffer& lhs, Buffer& rhs) noexcept {
    lhs.swap(rhs);
}
