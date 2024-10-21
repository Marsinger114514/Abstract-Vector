#include <iostream>
#include "String.h"

void testStringClass() {
    try {
        // 默认构造函数
        String str1;
        std::cout << "Default constructed string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // C 风格字符串构造函数
        String str2("Hello");
        std::cout << "C-string constructed string: '" << str2 << "' (length: " << str2.length() << ")" << std::endl;

        // 拷贝构造函数
        String str3(str2);
        std::cout << "Copy constructed string: '" << str3 << "' (length: " << str3.length() << ")" << std::endl;

        // 移动构造函数
        String str4(std::move(str3));
        std::cout << "Move constructed string: '" << str4 << "' (length: " << str4.length() << ")" << std::endl;
        std::cout << "Original string after move: '" << str3 << "' (length: " << str3.length() << ")" << std::endl;

        // 拷贝赋值运算符
        str1 = str2;
        std::cout << "After copy assignment, str1: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // 移动赋值运算符
        str1 = std::move(str4);
        std::cout << "After move assignment, str1: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
        std::cout << "Original string after move assignment: '" << str4 << "' (length: " << str4.length() << ")" << std::endl;

        // 下标运算符
        std::cout << "Character at index 1: " << str1[1] << std::endl;
        try {
            std::cout << "Character at index 100: " << str1[100] << std::endl;
        } catch (const std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        // 字符串连接运算符
        String str5 = str1 + str2;
        std::cout << "Concatenated string: '" << str5 << "' (length: " << str5.length() << ")" << std::endl;

        // 字符串追加运算符
        str1 += str2;
        std::cout << "Appended string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // 比较运算符
        std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
        std::cout << "str1 != str2: " << (str1 != str2) << std::endl;
        std::cout << "str1 < str2: " << (str1 < str2) << std::endl;
        std::cout << "str1 <= str2: " << (str1 <= str2) << std::endl;
        std::cout << "str1 > str2: " << (str1 > str2) << std::endl;
        std::cout << "str1 >= str2: " << (str1 >= str2) << std::endl;

        // 流运算符
        std::cout << "Enter a string: ";
        String str6;
        std::cin >> str6;
        std::cout << "You entered: " << str6 << std::endl;

        // 清空字符串数据
        str6.clear();
        std::cout << "After clear, str6: '" << str6 << "' (length: " << str6.length() << ", empty: " << std::boolalpha << str6.empty() << ")" << std::endl;

        // 返回字符串的副本
        String str7 = str1.copy();
        std::cout << "Copied string: '" << str7 << "' (length: " << str7.length() << ")" << std::endl;

        // 返回字符串的大小
        std::cout << "Size of str1: " << str1.size() << std::endl;

        // 判断字符串是否为空
        std::cout << "Is str1 empty? " << std::boolalpha << str1.empty() << std::endl;

        // 逆转字符串
        str1.reverse();
        std::cout << "Reversed string: '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
        str1.reverse(); // Reverse back to original for further tests

        // 追加字符串
        str1.append(" World");
        std::cout << "Appended ' World': '" << str1 << "' (length: " << str1.length() << ")" << std::endl;

        // 擦除指定位置的子串
        str1.erase(5, 5); // Erase " World"
        std::cout << "After erase ' Hello': '" << str1 << "' (length: " << str1.length() << ")" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}


