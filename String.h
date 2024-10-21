#ifndef STRING_H
#define STRING_H

#include "VectorBase.h"
#include <cstring>
#include <iostream>

class String : public VectorBase<char> {
public:
    // ���캯��
    String(const char* str = "");
    String(const char* str, const unsigned int& n);
    String(const String& str);
    ~String();

    // ���������
    String operator+(const String& str);
    String& operator+=(const String& str);
    bool operator<(const String& str) const;
    bool operator<=(const String& str) const;
    bool operator>(const String& str) const;
    bool operator>=(const String& str) const;

    // ��Ҫ��Ա����
    const char* c_str() const;
    String copy() const;
    String& replace(const unsigned int& index, const unsigned int& len, const String& str);
    String substr(const int& index, const int& len) const;
    String& append(const String& str, const unsigned int& len);

    // ���麯����ʵ��
    void putout(ostream& out) const override;
    void putin(istream& in) override;

    // �������غ���
    friend ostream& operator<<(ostream& out, const VectorBase<char>& str);
    friend istream& operator>>(istream& in,VectorBase<char>& str);
    friend istream& getline(istream& in, String& str, const char delim);
    friend int stoi(const String& str);
private:
    void setString(const char* str, unsigned int len);
    void resize() {
        capacity *= 2; // ����������
        char* newHead = new char[capacity];
        strcpy(newHead, head); // ����ԭʼ����
        delete[] head; // �ͷž��ڴ�
        head = newHead; // ����ָ��
    }
};

#endif
