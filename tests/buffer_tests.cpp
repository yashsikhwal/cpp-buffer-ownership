#include "buffer.hpp"

#include <iostream>
#include <stdexcept>
#include <utility>

namespace {

void require(bool condition, const char* message) {
    if (!condition) {
        throw std::runtime_error(message);
    }
}

void testConstructionAndDeepCopy() {
    Buffer original{1, 2, 3};
    Buffer copy(original);

    require(copy.size() == 3, "copy has the wrong size");
    require(copy.data() != original.data(), "copy shares storage with original");
    copy[0] = 9;
    require(original[0] == 1, "modifying copy changed original");

    Buffer assigned{4};
    assigned = original;
    require(assigned.size() == 3 && assigned[2] == 3, "copy assignment failed");
    assigned = assigned;
    require(assigned.size() == 3 && assigned[0] == 1, "self-copy assignment failed");

    Buffer empty;
    Buffer emptyCopy(empty);
    require(emptyCopy.empty() && emptyCopy.data() == nullptr, "empty copy is not empty");
}

void testMoveOperations() {
    Buffer source{5, 6};
    int* originalData = source.data();
    Buffer moved(std::move(source));
    require(moved.data() == originalData && moved.size() == 2, "move construction failed");
    require(source.empty() && source.data() == nullptr, "move source is not empty");

    Buffer destination{1};
    destination = std::move(moved);
    require(destination.data() == originalData && destination.size() == 2, "move assignment failed");
    require(moved.empty() && moved.data() == nullptr, "move-assigned source is not empty");
    destination = std::move(destination);
    require(destination.size() == 2 && destination[1] == 6, "self-move assignment failed");
}

void testSwap() {
    Buffer lhs{1, 2};
    Buffer rhs{3};
    swap(lhs, rhs);
    require(lhs.size() == 1 && lhs[0] == 3, "left side of swap failed");
    require(rhs.size() == 2 && rhs[0] == 1 && rhs[1] == 2, "right side of swap failed");
}

}  // namespace

int main() {
    try {
        testConstructionAndDeepCopy();
        testMoveOperations();
        testSwap();
    } catch (const std::exception& error) {
        std::cerr << "Buffer test failed: " << error.what() << '\n';
        return 1;
    }
    std::cout << "All buffer tests passed\n";
    return 0;
}
