#include "VectorBase.h"
#include <iostream>
#include <conio.h>
int Pos(char ch, const char *str)			// ����ָ���ַ�ch���ַ���str�е��±ꡣ������ʱ����-1
{
    int i;
    for(i=0; str[i]!='\0'; i++)
        if(ch==str[i])
            return i;
    return -1;
}

int Choice(const char *prompt, const char *options="");	// ��������
int Choice(const char *prompt, const char *options)		// �������塣�����ʾ��Ϣprompt������ѡ����ַ������ء�
{
    int key;
    cout << prompt << "{";
    for(int i=0; options[i]!='\0'; i++)
    {
        if(' ' < (options[i] & 0x7f) && (options[i] & 0x7f) < 127)	// ѡ��options�еĿɴ�ӡ�ַ�
            cout << options[i] << ' ';
        else														// ѡ��options�еĲ��ֿ����ַ�
        {
            switch(options[i])
            {
                case '\t':   cout << "[Tab] ";   break;					// ѡ���е�Tab�ַ�'\t'����ASCII����9��
                case '\x1b': cout << "[Esc] ";   break;					// ѡ���е�Esc�ַ�'\x1b'����ASCII����27��
                case ' ':    cout << "[Space] "; break;					// ѡ���еĿո��ַ�' '����ASCII����32��
            }
        }
    }
    cout << "\b}: ";					// '\b'�˸�����һ��������һ�����
    do
    {
        key = getch();
    }while(options[0]!='\0' && Pos(key, options)<0); // ��optionsΪ�ճ���Ϊ0���ַ����������������ƣ�����������Ӧ����optins�С�
    cout << endl;
    return key;
}

int main() {
    void testStringClass(), testVectorClass(), testderivedstring(), testStringDiversity(), testStringDiversity2();
    int key;
    while(true)
    {
        cout << "����������ģ�������Ͷ�̬����" << endl;
        cout << "1 --- ������ģ�����" << endl;
        cout << "2 --- �ַ������" << endl;
        cout << "3 --- �ַ�����������" << endl;
        cout << "4 --- �ַ����̬����1" << endl;
        cout << "5 --- �ַ����̬����2" << endl;
        key = Choice("\n��ѡ��", "12345\x1b");
        cout << "\n\n";
        if(key==27)		// '\x1b'����27��ָESC��
            break;
        switch(key)
        {
            case '1':	testVectorClass();			    break;
            case '2':	testStringClass();	            break;
            case '3':	testderivedstring();			break;
            case '4':	testStringDiversity();			break;
            case '5':	testStringDiversity2();			break;
        }
    }
    return 0;
}