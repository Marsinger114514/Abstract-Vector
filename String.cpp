#include "String.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

// Ĭ�Ϲ��캯��
String::String(const char* str) {
    size = strlen(str);
    capacity = std::max(1024u, size * 2); // ���ó�ʼ����
    head = new char[capacity];
    strcpy(head, str);
}

// ָ�����ȵĹ��캯��
String::String(const char* str, const unsigned int& n) {
    size = n;
    capacity = std::max(1024u, size * 2);
    head = new char[capacity];
    strncpy(head, str, n);
    head[n] = '\0';
}

// �������캯��
String::String(const String& str) : VectorBase<char>(str) {
    size = str.size;
    capacity = str.capacity;
    head = new char[capacity];
    strcpy(head, str.head);
}

// ��������
String::~String() {
    delete[] head;
}

// ���������
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

// ��Ҫ��Ա����
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

    // ���Ҫ�滻�ĳ����Ƿ���Ч
    if (index + len > size) {
        throw std::out_of_range("Length exceeds current string size");
    }

    unsigned int newLen = str.size; // ���ַ����ĳ���
    unsigned int newSize = size - len + newLen; // �����滻����´�С

    // ����´�С������ǰ����������չ����
    if (newSize >= capacity) {
        // ��չ����
        unsigned int newCapacity = std::max(2 * capacity, newSize + 1); // �����������ǵ�ǰ����������
        char* newHead = new char[newCapacity];

        // ���� index ֮ǰ������
        strncpy(newHead, head, index);

        // �������ַ���
        strncpy(newHead + index, str.head, newLen);

        // ���� index + len ֮�������
        strncpy(newHead + index + newLen, head + index + len, size - (index + len));

        // ��ӽ�����
        newHead[newSize] = '\0';

        delete[] head; // �ͷž��ڴ�
        head = newHead; // ����ָ��
        capacity = newCapacity; // ��������
    } else {
        // ��ǰ�����㹻��ֱ�ӽ����滻
        memmove(head + index + newLen, head + index + len, size - (index + len) + 1); // +1 ȷ������ '\0'
        strncpy(head + index, str.head, newLen); // �������ַ���
    }

    size = newSize; // �����ַ�����С
    return *this; // ������������
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

// ���麯����ʵ��
void String::putout(ostream& out) const {
    out << head;
}

void String::putin(istream& in) {
    char buffer[1024];
    in >> buffer;
    *this = String(buffer);
}

// �������غ���
ostream& operator<<(ostream& out, const VectorBase<char>& str) {
    for (unsigned int i = 0; i < str.getsize(); ++i) {
        out << str[i];  // ʹ�� VectorBase �� operator[] ����Ԫ��
    }
    return out;
}

istream& operator>>(istream& in, VectorBase<char>& str) {
    str.clear();

    char ch;
    // �����ȡ�ַ���ֱ�������հ��ַ���������
    while (in.get(ch)) {
        if (isspace(ch)) {
            break;  // �����հ��ַ�ʱ����
        }
        str.push_back(ch);  // ���ַ����뵽 VectorBase<char> ��
    }

    return in;  // ��������������֧����ʽ����
}

istream& getline(istream& in, String& str, const char delim) {
    str.clear();

    char ch;
    // ���ַ���ȡ��ֱ������ָ���ķָ�����������
    while (in.get(ch)) {
        if (ch == delim) {
            break;  // �����ָ���ʱ����
        }
        str.push_back(ch);  // ���ַ���ӵ� String ����
    }

    return in;  // ��������������֧����ʽ����
}

int stoi(const String& str) {
    const char* cstr = str.c_str();

    // ���ñ�׼���е� std::stoi �����ַ�����������ת��
    try {
        return std::stoi(cstr);  // ����ת���������
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: cannot convert to int\n";
        return 0;  // ������Ч���룬����Ĭ��ֵ
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range: number too large\n";
        return 0;  // ��������Χ�����룬����Ĭ��ֵ
    }
}

