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
void testDiversity1() {
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
        std::cout << "str2.erase(100,200) =  ";
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

    //测试[]
    try {
        cout << "str4[0] : " << str4[0] << endl;
        cout << "str4[100] : " ;
        cout<< str4[100]  ;
    }catch (const std::out_of_range& e) {
        cout << "error: " << e.what() << endl;
    }

    //测试putin和putout
    String str5;
    VectorBase<char>* vec5 = &str5;
    cout<<"please input str5: ";
    vec5->putin(cin);
    cin.sync();
    cout<<"str5 :  "<<str5;
    vec5->putout(cout);

    //测试!=
    cout<<endl;
    VectorBase<char>* vec6 = new String("apple");
    VectorBase<char>* vec7 = new String("banana");
    VectorBase<char>* vec8 = new String("apple");

    // 测试不等于运算符
    std::cout << "Is str6(apple) != str7(banana)? " << (*vec6 != *vec7 ? "Yes" : "No") << std::endl;
    std::cout << "Is str6(apple) != str8(apple)? " << (*vec6 != *vec8 ? "Yes" : "No") << std::endl;

}
void testDiversity2() {
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
   }   catch(int) {cout<<"error"<<endl;}


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

    cout<<"test at()"<<std::endl;
    for (unsigned int i = 0; i < base1->getsize(); ++i) {
        std::cout << "vec[" << i << "] = " << base1->at(i) << std::endl;
    }
    try {
        Vector<int> vec5;
        VectorBase<int>* base5 = &vec5;
        std::cout << "vec5.at(0) : ";
        base5->at(0);
    }catch(int) {cout<<"error"<<endl;}

    // 测试 back
    try {
        std::cout << "vec1: " ;
        vec1.putout(std::cout);
        std::cout << "Last element of vec1: " << base1->back() << std::endl;

        Vector<int> vec5;
        VectorBase<int>* base5 = &vec5;
        std::cout << "Last element of vec5: ";
        base5->back();
    }catch(int) {cout<<"error"<<endl;}

    // 测试 pop_back
    base1->pop_back();
    std::cout << "After pop_back,last element of vec1: " << base1->back() << std::endl;
    try {
        Vector<int> vec5;
        VectorBase<int>* base5 = &vec5;
        std::cout << "After pop_back,last element of vec5: ";
        base5->pop_back();
    }catch(int) {cout<<"error"<<endl;}



}
