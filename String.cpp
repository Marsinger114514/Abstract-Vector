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
    size = str.size;
    capacity = str.capacity;
    head = new char[capacity];
    strcpy(head, str.head);
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
    if (index > size) {
        throw std::out_of_range("Index out of range");
    }

    // 检查要替换的长度是否有效
    if (index + len > size) {
        throw std::out_of_range("Length exceeds current string size");
    }

    unsigned int newLen = str.size; // 新字符串的长度
    unsigned int newSize = size - len + newLen; // 计算替换后的新大小

    // 如果新大小超过当前容量，需扩展容量
    if (newSize >= capacity) {
        // 扩展容量
        unsigned int newCapacity = std::max(2 * capacity, newSize + 1); // 新容量至少是当前容量的两倍
        char* newHead = new char[newCapacity];

        // 复制 index 之前的内容
        strncpy(newHead, head, index);

        // 插入新字符串
        strncpy(newHead + index, str.head, newLen);

        // 复制 index + len 之后的内容
        strncpy(newHead + index + newLen, head + index + len, size - (index + len));

        // 添加结束符
        newHead[newSize] = '\0';

        delete[] head; // 释放旧内存
        head = newHead; // 更新指针
        capacity = newCapacity; // 更新容量
    } else {
        // 当前容量足够，直接进行替换
        memmove(head + index + newLen, head + index + len, size - (index + len) + 1); // +1 确保包括 '\0'
        strncpy(head + index, str.head, newLen); // 插入新字符串
    }

    size = newSize; // 更新字符串大小
    return *this; // 返回自身引用
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

