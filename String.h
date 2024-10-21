#ifndef STRING_H
#define STRING_H

#include "VectorBase.h"

class String : public VectorBase<char> {
public:
    String(); // 默认构造函数
    String(const char* str); // 参数为C字符串的构造函数
    String(const String& other); // 拷贝构造函数
    String(String&& other) noexcept; // 移动构造函数
    ~String(); // 析构函数

    String& operator=(const String& other); // 拷贝赋值运算符
    String& operator=(String&& other) noexcept; // 移动赋值运算符

    size_t length() const; // 获取字符串长度
    const char* c_str() const; // 获取C字符串
    char& operator[](size_t index); // 重载[]运算符（可修改）
    const char& operator[](size_t index) const; // 重载[]运算符（只读）

    String operator+(const String& other) const; // 重载+运算符
    String& operator+=(const String& other); // 重载+=运算符

    bool operator<(const String& other) const; // 重载<运算符
    bool operator<=(const String& other) const; // 重载<=运算符
    bool operator>(const String& other) const; // 重载>运算符
    bool operator>=(const String& other) const; // 重载>=运算符
    bool operator==(const String& other) const; // 重载==运算符
    bool operator!=(const String& other) const; // 重载!=运算符

    friend std::ostream& operator<<(std::ostream& os, const String& str); // 重载<<运算符
    friend std::istream& operator>>(std::istream& is, String& str); // 重载>>运算符

    void clear(); // 清空字符串数据
    String copy() const; // 返回字符串的副本
    unsigned int size() const; // 返回字符串的大小
    bool empty() const; // 判断字符串是否为空
    String& reverse(); // 逆转字符串
    String& append(const String& str); // 追加字符串
    String& erase(const unsigned int& index, const unsigned int& len); // 擦除指定位置的子串

protected:
    void putin(std::istream& in) override; // 从输入流读取数据
    void putout(std::ostream& out) const override; // 向输出流写入数据
};

#endif // STRING_H