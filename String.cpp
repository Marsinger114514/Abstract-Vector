#include "String.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

// 默认构造函数
String::String(const char* str) {
    size = strlen(str);
    capacity = std::max(1024u, size * 2); // 设置初始容量
    head = new char[capacity];
    strcpy(head, str);
}

// 指定长度的构造函数
String::String(const char* str, const unsigned int& n) {
    size = n;
    capacity = std::max(1024u, size * 2);
    head = new char[capacity];
    strncpy(head, str, n);
    head[n] = '\0';
}

// 拷贝构造函数
String::String(const String& str) : VectorBase<char>(str) {
}

// 析构函数
String::~String() {
    delete[] head;
}

// 运算符重载
String String::operator+(const String& str) {
    String result(*this);
    result += str;
    return result;
}

String& String::operator+=(const String& str) {
    unsigned int newSize = size + str.size;
    if (newSize > capacity) {
        resize();
    }
    strcat(head, str.head);
    size = newSize;
    return *this;
}

bool String::operator<(const String& str) const {
    return strcmp(head, str.head) < 0;
}

bool String::operator<=(const String& str) const {
    return strcmp(head, str.head) <= 0;
}

bool String::operator>(const String& str) const {
    return strcmp(head, str.head) > 0;
}

bool String::operator>=(const String& str) const {
    return strcmp(head, str.head) >= 0;
}

// 主要成员函数
const char* String::c_str() const {
    return head;
}

String String::copy() const {
    return String(head);
}

String& String::replace(const unsigned int& index, const unsigned int& len, const String& str) {
    if (index + len > size) {
        throw std::out_of_range("Index out of range");
    }
    strncpy(head + index, str.head, len);
    return *this;
}

String String::substr(const int& index, const int& len) const {
    if (index + len > size) {
        throw std::out_of_range("Index out of range");
    }
    char* temp = new char[len + 1];
    strncpy(temp, head + index, len);
    temp[len] = '\0';
    String result(temp);
    delete[] temp;
    return result;
}

String& String::append(const String& str, const unsigned int& len) {
    unsigned int newSize = size + len;
    if (newSize > capacity) {
        resize();
    }
    strncat(head, str.head, len);
    size = newSize;
    return *this;
}

// 纯虚函数的实现
void String::putout(ostream& out) const {
    out << head;
}

void String::putin(istream& in) {
    char buffer[1024];
    in >> buffer;
    *this = String(buffer);
}

// 其他重载函数
ostream& operator<<(ostream& out, const String& str) {
    str.putout(out);
    return out;
}

istream& operator>>(istream& in, String& str) {
    str.putin(in);
    return in;
}

istream& getline(istream& in, String& str, const char delim) {
    char buffer[1024];
    in.getline(buffer, 1024, delim);
    str = String(buffer);
    return in;
}

int stoi(const String& str) {
    return std::stoi(std::string(str.c_str()));
}

