// DerivedString.cpp
#include "DerivedString.h"
#include <iostream>

void StringTest() {
    DerivedString ds;

    // 测试 operator[] 和 at
    try {
        std::cout << "Accessing out-of-bounds index: " << ds.at(0) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Exception caught:" <<e.what()<<std::endl;
    }

    // 测试 push_back, size, back, and pop_back
    ds.push_back('H');
    ds.push_back('e');
    ds.push_back('l');
    ds.push_back('l');
    ds.push_back('o');
    std::cout << "String after push_back: " << ds.getsize() << " characters" << std::endl;
    std::cout << "Last character (back): " << ds.back() << std::endl;
    ds.pop_back();
    std::cout << "String size after pop_back: " << ds.getsize() << std::endl;

    // 测试 insert 和 erase
    ds.insert(1, 'a', 1); // Insert 'a' at position 1
    ds.putout(std::cout); // Output: Hella
    ds.erase(3); // Erase character at position 3
    ds.putout(std::cout); // Output: Hell

    // 测试 erase with range
    ds.erase(2, 3); // Erase range from 2 to 3
    ds.putout(std::cout); // Output: He

    // 测试 empty and clear
    std::cout << "String empty before clear: " << (ds.empty() ? "Yes" : "No") << std::endl;
    ds.clear();
    std::cout << "String empty after clear: " << (ds.empty() ? "Yes" : "No") << std::endl;

    // 测试 swap and reverse
    DerivedString ds2;
    ds2.push_back('W');
    ds2.push_back('o');
    ds2.push_back('r');
    ds2.push_back('l');
    ds2.push_back('d');
    ds.swap(ds2);
    ds.putout(std::cout); // Output: World
    ds.reverse();
    ds.putout(std::cout); // Output: dlroW

    // 测试 operator== and !=
    DerivedString ds3;
    ds3.push_back('H');
    ds3.push_back('e');
    ds3.push_back('l');
    ds3.push_back('l');
    ds3.push_back('o');
    std::cout << "ds == ds2: " << (ds == ds2 ? "Yes" : "No") << std::endl;
    std::cout << "ds != ds3: " << (ds != ds3 ? "Yes" : "No") << std::endl;
}