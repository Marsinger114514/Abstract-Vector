#include "String.h"
#include <iostream>
#include <limits>
void testStringClass() {
    // 测试构造函数
    cout << "=== Testing Constructors ===" << endl;
    String s1("Hello");
    cout << "s1: " << s1 << endl;

    String s2("World", 3);
    cout << "s2 (with length 3): " << s2 << endl;

    String s3(s1);
    cout << "s3 (copy of s1): " << s3 << endl;

    // 测试运算符重载
    cout << "\n=== Testing Operator Overloads ===" << endl;
    String s4 = s1 + s2;
    cout << "s4 (s1 + s2): " << s4 << endl;

    s1 += s2;
    cout << "s1 after s1 += s2: " << s1 << endl;

    cout << "Is s1 < s2? " << (s1 < s2 ? "Yes" : "No") << endl;
    cout << "Is s1 <= s2? " << (s1 <= s2 ? "Yes" : "No") << endl;
    cout << "Is s1 > s2? " << (s1 > s2 ? "Yes" : "No") << endl;
    cout << "Is s1 >= s2? " << (s1 >= s2 ? "Yes" : "No") << endl;

    // 测试字符串操作
    cout << "\n=== Testing String Operations ===" << endl;
    cout << "s1.c_str(): " << s1.c_str() << endl;

    String s5 = s1.copy();
    cout << "s5 (copy of s1): " << s5 << endl;

    s1.replace(0, 5, s2);
    cout << "s1 after replacing 'Hello' with s2: " << s1 << endl;

    String s6 = s5.substr(0, 5);
    cout << "s6 (substring of s5 from 0, length 5): " << s6 << endl;

    s5.append(s1, 6);
    cout << "s5 after appending s1: " << s5 << endl;

    // 测试输入输出函数
    cout << "\n=== Testing I/O Functions ===" << endl;
    cout << "Enter a string: ";
    String s7;
    cin >> s7;
    cout << "You entered: " << s7 << endl;

    cout << "Enter a string with a delimiter (e.g., Hello, World!): ";
    String s8;
    getline(cin, s8, ',');
    cout << "String read until delimiter: " << s8 << endl;
    cin.sync();
    // 测试 stoi 函数
    cout << "\n=== Testing stoi Function ===" << endl;
    String s9("12345");
    int number = stoi(s9);  // 调用自定义的 stoi 函数
    cout << "Integer value of s9 ('12345'): " << number << endl;
}
