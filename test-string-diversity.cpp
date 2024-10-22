#include "String.h"
#include"Vector.h"
#include "VectorBase.h"
#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>
//单独测试派生类
void testderivedstring() {
    String str1;
    String str2;

    // 使用 putin 方法初始化 str1
    std::cout << "Please enter a string: ";
    str1.putin(std::cin);

    // 输出提示信息
    std::cout << "The string read: ";
    str1.putout(std::cout);
}

//联合测试
void testStringDiversity() {
    // 创建一个字符串对象并输出
    String str1("hello");
    VectorBase<char>* vec1 = &str1;
    cout << "str1 ="<<str1 << endl; // 输出 str1
    std::cout << "size of str1 = " << vec1->getsize() << std::endl;

    // 创建另一个字符串对象并拷贝构造一个新的对象
    String str2("HelloWorld");
    String str3(str2);
    VectorBase<char>* vec2 = &str2;
    VectorBase<char>* vec3 = &str3;
    cout << "str2 ="<<str2 << endl; // 输出 str2
    cout << "str3 ="<<str3 << endl; // 输出 str3

    // 在 str2 的位置 5 插入 'X' 三次
    vec2->insert(5, 'X', 3);
    std::cout << "str2.insert(5, 'X', 3)=  ";
    cout << str2 << endl;
    std::cout << "size of str2 = " << vec2->getsize() << std::endl;

    // 输出 str3
    std::cout << "str3 = " << str3 << std::endl;
    try {
        vec2->erase(0);
        std::cout << "str2.erase(0) =  ";
        cout << str2 << endl;
        std::cout << "str2.erase(100) =  ";
        vec2->erase(100);
    } catch (const std::out_of_range& e) {
        cout << "error: " << e.what() << endl;
    }

    try {
        // 从 str2 的位置 5 开始删除 7 个字符
        vec2->erase(5, 7);
        std::cout << "str2.erase(5, 7) =  ";
        cout << str2 << endl;
        std::cout << "size of str2 = " << vec2->getsize() << std::endl;

        // 尝试删除超出范围的字符（应该抛出异常）
        std::cout << "str2.erase(100) =  ";
        vec2->erase(100, 200);

    } catch (int) {
        cout << "error" << endl;
    }

    // 检查 str2 是否为空
    std::cout << "str2.empty : " << (vec2->empty() ? "yes" : "no") << std::endl;

    // 清空 str2
    vec2->clear();
    std::cout << "after clear,size of str2 = " << vec2->getsize() << std::endl;
    std::cout << "str2.empty : " << (vec2->empty() ? "yes" : "no") << std::endl;

    // 创建一个新的字符串对象并反转
    String str4("abcde");
    cout <<"str4 ="<< str4 << endl;
    VectorBase<char>* vec4 = &str4;
    vec4->reverse();

    cout << "str4.reverse():"<<str4 << endl;

    // 交换 str4 和 str1 的内容
    vec4->swap(str1);
    std::cout << "str4.swap(str2) : " << str4 << " " << str1 << endl;

    try {
        cout << "str4[0] : " << str4[0] << endl;
        cout << "str4[100] : " << str4[100]  ;
    }catch (const std::out_of_range& e) {
        cout << "error: " << e.what() << endl;
    }
}
void testStringDiversity2() {
    // 创建一个 Vector<int> 对象并输出
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    VectorBase<int>* base1 = &vec1;
    std::cout << "vec1: " ; // 输出 vec1
    vec1.putout(std::cout);
    std::cout << "size of vec1: " << base1->getsize() << std::endl;

    // 创建另一个 Vector<int> 对象并拷贝构造一个新的对象
    Vector<int> vec2;
    vec2.push_back(4);
    vec2.push_back(5);
    vec2.push_back(6);
    Vector<int> vec3(vec2);
    VectorBase<int>* base2 = &vec2;
    VectorBase<int>* base3 = &vec3;

    std::cout << "vec2: " ; // 输出 vec2
    vec2.putout(std::cout);
    std::cout << "vec3: " ; // 输出 vec3
    vec3.putout(std::cout);
    // 在 vec2 中插入元素
    base2->push_back(7);
    std::cout << "vec2,pushback(7): " ;
    vec2.putout(std::cout);
    std::cout << "size of vec2 : " << base2->getsize() << std::endl;

    // 使用 += 运算符
   try {
       std::cout << "vec2 += vec1 : ";
       vec2 += vec1;
       vec2.putout(std::cout);
       std::cout << "size of vec2 : " << base2->getsize() << std::endl;
   }catch(int) {cout<<"error"<<endl;}
     vec2.erase(0);
    std::cout << "after str2.erase(0),vec2 :";
    vec2.putout(std::cout);
    vec2 += vec1;
    std::cout << "vec2 += vec1: ";
    vec2.putout(std::cout);
    std::cout << "size of vec2 : " << base2->getsize() << std::endl;
    // 使用 + 运算符
   try {
       Vector<int> vec4 = vec2 + vec3;
       VectorBase<int>* base4 = &vec4;
       std::cout << "vec4 = vec2 + vec3: "  ;
       vec4.putout(std::cout);
       std::cout << "size of vec4: " << base4->getsize() << std::endl;
   }catch(int){cout << "error" << endl;}

    // 清空 vec2
    base2->clear();
    std::cout << "after clear ,size of vec2 : " << base2->getsize() << std::endl;


}
