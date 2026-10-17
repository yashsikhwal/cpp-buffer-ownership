
#include <cstddef>
#include <memory>


class Buffer {
private:
    std::size_t size_{0};
    std::unique_ptr<int[]> data_;

public:
    explicit Buffer(std::size_t size)
        : size_(size),
          data_(size ? std::make_unique<int[]>(size) : nullptr) {}

    // Copy constructor
    Buffer(const Buffer& other)
    {
        if(other.size_ != 0)
        {
            size_ = other.size_;
            data_ = std::make_unique<int[]>(size_);
            for(std::size_t i=0; i<size_; i++)
            {
                data_[i] = other.data_[i];
            }
        }
        else
        {
            size_ = 0;
            data_ = nullptr;
        }
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept 
        : size_(other.size_), 
          data_(std::move(other.data_))
    {
        other.data_ = nullptr;
        other.size_ = 0;
    }

    // Copy assignment operator
    Buffer& operator=(const Buffer& other)
    {
        // Return the same if the objects are same
        if(this == &other)
        {
            return *this;
        }

        // Guard to handle memory allocation error
        auto newData = other.data_ == nullptr ? nullptr : std::make_unique<int[]>(other.size_);

        for(std::size_t i=0; i<other.size_; i++)
        {
            newData[i] = other.data_[i];
        }

        this->data_ = std::move(newData);
        this->size_ = other.size_;

        return *this;
    }

    // Move assignment operator
    Buffer& operator=(Buffer&& other) noexcept
    {
        // Return the same if the objects are same
        if(this == &other)
        {
            return *this;
        }

        this->data_ = std::move(other.data_);
        this->size_ = other.size_;
        other.size_ = 0;
        return *this;
    }

    ~Buffer() = default;

    std::size_t size() const noexcept {
        return size_;
    }

    int& operator[](std::size_t index) {
        return data_[index];
    }

    const int& operator[](std::size_t index) const {
        return data_[index];
    }

    const int* data() const noexcept {
        return data_.get();
    }

    // Swap the two objects
    void swap(Buffer& other) noexcept
    {
        using std::swap;

        swap(size_, other.size_);
        swap(data_, other.data_);
    }
};
