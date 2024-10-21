#include "String.h"
#include "VectorBase.h"
#include <iostream>
#include <string>
#include <sstream>
//��������������
void testderivedstring() {
    String str1;
    String str2;

    // ʹ�� putin ������ʼ�� str1
    std::cout << "Please enter a string: ";
    str1.putin(std::cin);

    // �����ʾ��Ϣ
    std::cout << "The string read: ";
    str1.putout(std::cout);
}

//���ϲ���
void testStringDiversity() {
    // Ĭ�Ϲ��캯��
    String str1;
    VectorBase<char>* vec1 = &str1;
    std::cout << "Ĭ�Ϲ��캯��: ��С = " << vec1->getsize() << std::endl;

    // �������캯��
    String str2;
    std::istringstream initStream("HelloWorld");
    str2.putin(initStream);

    String str3(str2);  // ʹ�ÿ������캯��
    VectorBase<char>* vec2 = &str2;
    VectorBase<char>* vec3 = &str3;
    std::cout << "��������: str2 = ";
    vec2->putout(std::cout);
    std::cout << "str3 = ";
    vec3->putout(std::cout);


}
void testStringDiversity2() {
    // Ĭ�Ϲ��캯��
    String str1;
    VectorBase<char>* vec1 = &str1;
    std::cout << "Ĭ�Ϲ��캯��: ��С = " << vec1->getsize() << std::endl;

    // �������캯��
    String str2;
    std::istringstream initStream("HelloWorld");
    str2.putin(initStream);
    String str3(str2);  // ʹ�ÿ������캯��
    VectorBase<char>* vec2 = &str2;
    VectorBase<char>* vec3 = &str3;
    std::cout << "�������캯��: str2 = ";
    vec2->putout(std::cout);
    std::cout << "str3 = ";
    vec3->putout(std::cout);

    // getsize ����
    std::cout << "getsize ���� (��ʼ): ��С = " << vec2->getsize() << std::endl;

    // insert ����
    vec2->insert(5, 'X', 3);
    std::cout << "insert ���� (���� 'XXX' ��λ�� 5): ";
    vec2->putout(std::cout);
    std::cout << "��С = " << vec2->getsize() << std::endl;

    // erase ����
    vec2->erase(5, 7);
    std::cout << "erase ���� (ɾ��λ�� 5 �� 7): ";
    vec2->putout(std::cout);
    std::cout << "��С = " << vec2->getsize() << std::endl;

    // putin ����
    std::istringstream iss("NewWorld");
    vec2->putin(iss);
    std::cout << "putin ���� (��ȡ 'NewWorld'): ";
    vec2->putout(std::cout);

    // push_back ����
    vec2->push_back('!');
    std::cout << "push_back ���� (��� '!'): ";
    vec2->putout(std::cout);

    // pop_back ����
    vec2->pop_back();
    std::cout << "pop_back ���� (�Ƴ����һ���ַ�): ";
    vec2->putout(std::cout);

    // back ����
    std::cout << "back ���� (β���ַ�): " << vec2->back() << std::endl;

    // at ����
    std::cout << "at ���� (λ�� 3 ���ַ�): " << vec2->at(3) << std::endl;

    // empty ����
    std::cout << "empty ���� (��ʼ): " << (vec2->empty() ? "��" : "��") << std::endl;
    vec2->clear();
    std::cout << "clear ����: ��С = " << vec2->getsize() << std::endl;
    std::cout << "empty ���� (�����): " << (vec2->empty() ? "��" : "��") << std::endl;

    // reverse ����
    std::istringstream initStream3("abcde");
    vec2->putin(initStream);
    vec2->reverse();
    std::cout << "reverse ����: ";
    vec2->putout(std::cout);
}
