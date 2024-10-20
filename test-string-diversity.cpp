#include "DerivedString.h"
#include"VectorBase.h"
#include <iostream>
#include <string>
#include <sstream>
//单独测试派生类
void testderivedstring() {
    DerivedString str1;
    DerivedString str2;

    // 使用 putin 方法初始化 str1
    std::cout << "Please enter a string: ";
    str1.putin(std::cin);

    // 输出提示信息
    std::cout << "The string read: ";
    str1.putout(std::cout);
}

//联合测试
void testStringDiversity() {
    // 默认构造函数
    DerivedString str1;
    VectorBase<char>* vec1 = &str1;
    std::cout << "默认构造函数: 大小 = " << vec1->getsize() << std::endl;

    // 拷贝构造函数
    DerivedString str2;
    std::istringstream initStream("HelloWorld");
    str2.putin(initStream);

    DerivedString str3(str2);  // 使用拷贝构造函数
    VectorBase<char>* vec2 = &str2;
    VectorBase<char>* vec3 = &str3;
    std::cout << "拷贝构造: str2 = ";
    vec2->putout(std::cout);
    std::cout << "str3 = ";
    vec3->putout(std::cout);


}
void testStringDiversity2() {
    // 默认构造函数
    DerivedString str1;
    VectorBase<char>* vec1 = &str1;
    std::cout << "默认构造函数: 大小 = " << vec1->getsize() << std::endl;

    // 拷贝构造函数
    DerivedString str2;
    std::istringstream initStream("HelloWorld");
    str2.putin(initStream);
    DerivedString str3(str2);  // 使用拷贝构造函数
    VectorBase<char>* vec2 = &str2;
    VectorBase<char>* vec3 = &str3;
    std::cout << "拷贝构造函数: str2 = ";
    vec2->putout(std::cout);
    std::cout << "str3 = ";
    vec3->putout(std::cout);

    // getsize 方法
    std::cout << "getsize 方法 (初始): 大小 = " << vec2->getsize() << std::endl;

    // insert 方法
    vec2->insert(5, 'X', 3);
    std::cout << "insert 方法 (插入 'XXX' 在位置 5): ";
    vec2->putout(std::cout);
    std::cout << "大小 = " << vec2->getsize() << std::endl;

    // erase 方法
    vec2->erase(5, 7);
    std::cout << "erase 方法 (删除位置 5 到 7): ";
    vec2->putout(std::cout);
    std::cout << "大小 = " << vec2->getsize() << std::endl;

    // putin 方法
    std::istringstream iss("NewWorld");
    vec2->putin(iss);
    std::cout << "putin 方法 (读取 'NewWorld'): ";
    vec2->putout(std::cout);

    // push_back 方法
    vec2->push_back('!');
    std::cout << "push_back 方法 (添加 '!'): ";
    vec2->putout(std::cout);

    // pop_back 方法
    vec2->pop_back();
    std::cout << "pop_back 方法 (移除最后一个字符): ";
    vec2->putout(std::cout);

    // back 方法
    std::cout << "back 方法 (尾部字符): " << vec2->back() << std::endl;

    // at 方法
    std::cout << "at 方法 (位置 3 的字符): " << vec2->at(3) << std::endl;

    // empty 方法
    std::cout << "empty 方法 (初始): " << (vec2->empty() ? "是" : "否") << std::endl;
    vec2->clear();
    std::cout << "clear 方法: 大小 = " << vec2->getsize() << std::endl;
    std::cout << "empty 方法 (清除后): " << (vec2->empty() ? "是" : "否") << std::endl;

    // reverse 方法
    std::istringstream initStream3("abcde");
    vec2->putin(initStream);
    vec2->reverse();
    std::cout << "reverse 方法: ";
    vec2->putout(std::cout);
}

int main() {
    //单独测试派生类
    testderivedstring();
    return 0;
}