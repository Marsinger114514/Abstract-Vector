// DerivedVector.cpp
#include "DerivedVector.h"
#include <iostream>

int main() {
    DerivedVector<int> dv;

    // 测试 operator[] 和 at
    try {
        std::cout << "Accessing out-of-bounds index: " << dv.at(0) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught:" <<e.what()<<std::endl;
    }

    // 测试 push_back, size, back, and pop_back
    dv.push_back(1);
    dv.push_back(2);
    dv.push_back(3);
    std::cout << "Vector size after push_back: " << dv.getsize() << std::endl;
    std::cout << "Last element (back): " << dv.back() << std::endl;
    dv.pop_back();
    std::cout << "Vector size after pop_back: " << dv.getsize() << std::endl;

    // 测试 insert 和 erase
    dv.insert(0, 4, 1); // Insert 4 at position 0
    dv.putout(std::cout); // Output: 4 1 2
    dv.erase(1); // Erase element at position 1
    dv.putout(std::cout); // Output: 4 2

    // 测试 erase with range
    dv.erase(0, 1); // Erase range from 0 to 1
    dv.putout(std::cout); // Output: 2

    // 测试 empty and clear
    std::cout << "Vector empty before clear: " << (dv.empty() ? "Yes" : "No") << std::endl;
    dv.clear();
    std::cout << "Vector empty after clear: " << (dv.empty() ? "Yes" : "No") << std::endl;

    // 测试 swap and reverse
    DerivedVector<int> dv2;
    dv2.push_back(5);
    dv2.push_back(6);
    dv.swap(dv2);
    dv.putout(std::cout); // Output: 5 6
    dv.reverse();
    dv.putout(std::cout); // Output: 6 5

    // 测试 operator== and !=
    DerivedVector<int> dv3;
    dv3.push_back(5);
    dv3.push_back(6);
    std::cout << "dv == dv2: " << (dv == dv2 ? "Yes" : "No") << std::endl;
    std::cout << "dv != dv3: " << (dv != dv3 ? "Yes" : "No") << std::endl;

    return 0;
}