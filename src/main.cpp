#include "buffer.hpp"
#include <iostream>
#include <utility>
#include <cassert>

void demonstrateCopyConstruction()
{
    Buffer buff1(3);

    buff1[0] = 5;
    buff1[1] = 5;
    buff1[2] = 5;
    
    // Copy a buffer and modify the copy; the original must remain unchanged
    Buffer buff2 = buff1;
    buff2[0] = 7;
    std::cout << "Independent allocations: " << (buff1.data() != buff2.data()) << '\n';
    std::cout << "Original " << buff1[0] << std::endl; 
    std::cout << "Copy " << buff2[0] << std::endl;    
}

void demonstrateMoveConstruction()
{
    Buffer buff1(3);
    buff1[0] = 5;

    const int* originalAddress = buff1.data();

    Buffer buff3(std::move(buff1));

    std::cout << std::boolalpha;
    std::cout << "Allocation transferred: "
              << (buff3.data() == originalAddress) << '\n';
    std::cout << "Source empty: "
              << (buff1.size() == 0 && buff1.data() == nullptr) << '\n';
    std::cout << "Value preserved: " << buff3[0] << '\n';
}

void demonstrateCopyAssignment()
{
    // Copy-assign buffers of different sizes
    Buffer buff4(2);
    Buffer buff5(3);

    std::cout << "Size before copy " << buff4.size() << std::endl;
    buff4 = buff5;
    std::cout << "Size after copy " << buff4.size() << std::endl;
}

void demonstrateMoveAssignment()
{
    // Move-assign buffers of different sizes
    Buffer destination(2);
    Buffer source(8);

    std::cout << "Size before move " << destination.size() << std::endl;
    destination = std::move(source);
    std::cout << "Size after move " << destination.size() << std::endl;
    assert(source.data() != destination.data());
}

void demonstrateSwap()
{
    // Swap buffers of different sizes
    Buffer buff7(8);
    Buffer buff8(10);
    std::cout << "Size before swap " << buff7.size() << std::endl;
    buff7.swap(buff8);
    std::cout << "Size after swap " << buff7.size() << std::endl;
    assert(buff7.data() != buff8.data());
}

void demonstrateCopyAssignmentToEmptyBuffer()
{
    // Copy-assign an empty buffer
    Buffer buffEmpty(0);
    Buffer source(10);
    std::cout << "Size before copy " << buffEmpty.size() << std::endl;
    buffEmpty = source;
    std::cout << "Size after copy " << buffEmpty.size() << std::endl;
}

void demonstrateSelfAssignment()
{
    // Self-copy and self-move assignment
    Buffer buff9(3);
    std::cout << "Size before self-copy " << buff9.size() << std::endl;
    buff9 = buff9;
    std::cout << "Size after self-copy " << buff9.size() << std::endl;

    std::cout << "Size before self-move " << buff9.size() << std::endl;
    buff9 = std::move(buff9);
    std::cout << "Size after self-move " << buff9.size() << std::endl;
}

int main()
{
    demonstrateCopyConstruction();
    demonstrateMoveConstruction();
    demonstrateCopyAssignment();
    demonstrateMoveAssignment();
    demonstrateSwap();
    demonstrateCopyAssignmentToEmptyBuffer();
    demonstrateSelfAssignment();
}