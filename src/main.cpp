#include "buffer.hpp"

#include <iostream>
#include <utility>

int main() {
    Buffer original{1, 2, 3, 4};
    Buffer copy = original;
    copy[0] = 10;

    std::cout << "Original first value: " << original[0] << '\n';
    std::cout << "Copy first value: " << copy[0] << '\n';

    Buffer moved = std::move(copy);
    std::cout << "Moved buffer size: " << moved.size() << '\n';
    std::cout << "Source after move is empty: " << std::boolalpha << copy.empty() << '\n';

    Buffer other{7, 8};
    swap(original, other);
    std::cout << "Original size after swap: " << original.size() << '\n';
}
