#ifndef STRING_H
#define STRING_H

#include "VectorBase.h"
#include <cstring>
#include <iostream>

class String : public VectorBase<char> {
public:
    // 构造函数
    String(const char* str = "");
    String(const char* str, const unsigned int& n);
    String(const String& str);
    ~String();

    // 运算符重载
    String operator+(const String& str);
    String& operator+=(const String& str);
    bool operator<(const String& str) const;
    bool operator<=(const String& str) const;
    bool operator>(const String& str) const;
    bool operator>=(const String& str) const;

    // 主要成员函数
    const char* c_str() const;
    String copy() const;
    String& replace(const unsigned int& index, const unsigned int& len, const String& str);
    String substr(const int& index, const int& len) const;
    String& append(const String& str, const unsigned int& len);

    // 纯虚函数的实现
    void putout(ostream& out) const override;
    void putin(istream& in) override;

    // 其他重载函数
    friend ostream& operator<<(ostream& out, const VectorBase<char>& str);
    friend istream& operator>>(istream& in,VectorBase<char>& str);
    friend istream& getline(istream& in, String& str, const char delim);
    friend int stoi(const String& str);
private:
    void setString(const char* str, unsigned int len);
    void resize() {
        capacity *= 2; // 将容量翻倍
        char* newHead = new char[capacity];
        strcpy(newHead, head); // 复制原始内容
        delete[] head; // 释放旧内存
        head = newHead; // 更新指针
    }
};

#endif
