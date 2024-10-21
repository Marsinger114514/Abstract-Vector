#include "String.h"
#include <cstring>
#include <iostream>
#include <utility>

// 默认构造函数
String::String() : VectorBase<char>() {}

// 参数为C字符串的构造函数
String::String(const char* str) : VectorBase<char>() {
    if (str) {
        while (*str) {
            this->push_back(*str++);
        }
    }
}

// 拷贝构造函数
String::String(const String& other) : VectorBase<char>(other) {}

// 移动构造函数
String::String(String&& other) noexcept : VectorBase<char>(std::move(other)) {}

// 析构函数
String::~String() {}

// 拷贝赋值运算符
String& String::operator=(const String& other) {
    if (this != &other) {
        VectorBase<char>::operator=(other);
    }
    return *this;
}

// 移动赋值运算符
String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        VectorBase<char>::operator=(std::move(other));
    }
    return *this;
}

// 获取字符串长度
size_t String::length() const {
    return this->size();
}

// 获取C字符串
const char* String::c_str() const {
    static char buffer[1024] = {0}; // 假设字符串长度不会超过1024
    for (size_t i = 0; i < this->size(); ++i) {
        buffer[i] = this->head[i];
    }
    buffer[this->size()] = '\0';
    return buffer;
}

// 重载[]运算符（可修改）
char& String::operator[](size_t index) {
    return this->head[index];
}

// 重载[]运算符（只读）
const char& String::operator[](size_t index) const {
    return this->head[index];
}

// 重载+运算符
String String::operator+(const String& other) const {
    String result(*this);
    for (size_t i = 0; i < other.size(); ++i) {
        result.push_back(other.head[i]);
    }
    return result;
}

// 重载+=运算符
String& String::operator+=(const String& other) {
    for (size_t i = 0; i < other.size(); ++i) {
        this->push_back(other.head[i]);
    }
    return *this;
}

// 重载<运算符
bool String::operator<(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) < 0;
}

// 重载<=运算符
bool String::operator<=(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) <= 0;
}

// 重载>运算符
bool String::operator>(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) > 0;
}

// 重载>=运算符
bool String::operator>=(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) >= 0;
}

// 重载==运算符
bool String::operator==(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) == 0;
}

// 重载!=运算符
bool String::operator!=(const String& other) const {
    return std::strcmp(this->c_str(), other.c_str()) != 0;
}

// 重载<<运算符
std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.c_str();
    return os;
}

// 重载>>运算符
std::istream& operator>>(std::istream& is, String& str) {
    static char buffer[1024];
    is >> buffer;
    str = buffer;
    return is;
}

// 清空字符串数据
void String::clear() {
    VectorBase<char>::clear(); // 调用基类的 clear 方法
}

// 返回字符串的副本
String String::copy() const {
    return *this;
}

// 返回字符串的大小
unsigned int String::size() const {
    return this->getsize();
}

// 判断字符串是否为空
bool String::empty() const {
    return this->empty();
}

// 逆转字符串
String& String::reverse() {
    VectorBase<char>::reverse(); // 调用基类的 reverse 方法
    return *this;
}

// 追加字符串
String& String::append(const String& str) {
    for (size_t i = 0; i < str.size(); ++i) {
        this->push_back(str.head[i]);
    }
    return *this;
}

// 擦除指定位置的子串
String& String::erase(const unsigned int& index, const unsigned int& len) {
    // 首先检查 index 是否越界
    if (index > this->size()) {
        throw std::out_of_range("Index is greater than the size of the string");
    }

    // 计算实际要删除的元素数量，防止越界
    unsigned int actual_len = (index + len > this->size()) ? (this->size() - index) : len;

    // 从 VectorBase 移除元素
    for (unsigned int i = index; i < this->size() - actual_len; ++i) {
        this->at(i) = this->at(i + actual_len);
    }

    // 删除多余的元素
    while (actual_len-- > 0) {
        this->pop_back();
    }

    return *this;
}

// 从输入流读取数据
void String::putin(std::istream& in) {
    char ch;
    in.read(&ch, 1);
    while (!in.eof() && ch != '\n') {
        this->push_back(ch);
        in.read(&ch, 1);
    }
}

// 向输出流写入数据
void String::putout(std::ostream& out) const {
    for (size_t i = 0; i < this->size(); ++i) {
        out << this->head[i];
    }
}