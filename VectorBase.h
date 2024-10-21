//VectorBase.h
#ifndef VECTORBASE_H
#define VECTORBASE_H
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class VectorBase {
public:
    VectorBase() : head(nullptr), size(0), capacity(1024) {}    // ���캯��

    VectorBase(const VectorBase<T>& other) : size(other.size), capacity(other.capacity)     //�������
    {
        head = new T[capacity];
        for (int i = 0; i < size; i++) {
            head[i] = other.head[i];
        }
    }
    // ����µĹ��캯�����������ó�ʼ����
    VectorBase(unsigned int initialCapacity) : head(nullptr), size(0), capacity(initialCapacity) {
        if (capacity > 0) {
            head = new T[capacity];
        }
    }
    virtual ~VectorBase()    // ��������
    {
        clear();
        delete[] head;
    }

    T& operator[](const unsigned int& pos) const;    // �����±�Ϊpos��Ԫ��
    bool operator==(const VectorBase<T>& v) const;    // �жϱ�������v�Ƿ���ͬ
    bool operator!=(const VectorBase<T>& v) const;	//�жϱ�������v�Ƿ�ͬ
    unsigned int getsize()const;	//����������С
    unsigned int getcapacity()const;	//������������
    void insert(const unsigned int&, const T&, const unsigned int&);	//��posλ�ú����n��Ԫ��val
    void erase(const unsigned int& pos);	//ɾ��posλ�õ�һ��Ԫ��
    void erase(const unsigned int& lt, const unsigned int& rt);	//ɾ����[left,right]�������ڵ�����Ԫ�ء�
    void push_back(const T &val);	//��β������һ��Ԫ��
    void pop_back();	//����β��Ԫ��
    T back();	//����β��Ԫ��
    T& at(const unsigned int& pos);	//�����±�Ϊpos��Ԫ��
    bool empty() const;	//�ж������Ƿ�Ϊ��
    void clear();	//�����������Ԫ��
    void swap(VectorBase<T>& v);	//����������v����;
    void reverse();	//��ת����
    virtual void putout(ostream& out) const = 0;    // ���麯�� putout
    virtual void putin(istream& in) = 0;    // ���麯�� putin

protected:
    T* head;
    unsigned int size;
	unsigned int capacity;
    void resize()
    {
    	 capacity *= 2;
         T* new_head = new T[capacity];
         for (int i = 0; i <size; i++)
         {
         	new_head[i] = head[i];
         }
         delete[] head;
         head = new_head;
    }
};

template <typename T>
T& VectorBase<T>::operator[](const unsigned int& pos) const {
    if (pos >= size) {
        throw std::out_of_range("Index out of range");
    }
    return head[pos];
}

    template <typename T>
    bool VectorBase<T>:: operator==(const VectorBase<T>& v) const
    {
        if (size != v.size) {
            return false;
        }
        for (unsigned int i = 0; i < size; ++i) {
            if (head[i] != v.head[i]) {
                return false;
            }
        }
        return true;
    }

    template <typename T>
    bool VectorBase<T>:: operator!=(const VectorBase<T>& v) const
    {
        return !(*this == v);
    }

    template <typename T>
    unsigned int VectorBase<T>:: getsize() const
    {
        return size;
    }

    template <typename T>
    unsigned int VectorBase<T>:: getcapacity() const
    {
        return capacity;
    }
template <typename T>
void VectorBase<T>::insert(const unsigned int& pos, const T& val, const unsigned int& n) {
        if (pos < 0 || pos > size) {
            throw std::out_of_range("λ�ó�����Χ");
        }
        if (size + n > capacity) {
            resize();
        }
        // ��Ԫ������ƶ�n��λ��
        for (unsigned int i = size; i > pos; --i) {
            head[i + n - 1] = head[i - 1];
        }
        // ��posλ�ò���n��valԪ��
        for (unsigned int i = 0; i < n; ++i) {
            head[pos + i] = val;
        }
        size += n;
    }
template <typename T>
void VectorBase<T>::erase(const unsigned int& pos) {
    if (pos >= size) { // ע�⣺Ӧ���� >= size ������ > size
        throw std::out_of_range("Index out of range");
    }
    std::move(head + pos + 1, head + size, head + pos); // ʹ�� std::move
    size--;
}

    template <typename T>
    void VectorBase<T>:: erase(const unsigned int& lt, const unsigned int& rt)
    {
        if (lt > rt || rt >= size)
        {
            throw -1;
        }
        move(head + rt + 1, head + size, head + lt);
        size -= (rt - lt + 1);
    }

    template <typename T>
    void VectorBase<T>:: push_back(const T &val)
    {
        if (size == capacity)
        {
            resize();
        }
        head[size++] = val;
    }

    template <typename T>
    void VectorBase<T>:: pop_back()
    {
        if (size == 0) {
            throw -1;
        }
        size--;
    }

    template <typename T>
    T VectorBase<T>:: back()
    {
        if (size == 0)
        {
            throw -1;
        }
        return head[size - 1];
    }

    template <typename T>
    T& VectorBase<T>:: at(const unsigned int& pos)
    {
        if (pos < 0 || pos >= size)
        {
            throw -1;
        }
        return head[pos];
    }

    template <typename T>
    bool VectorBase<T>:: empty() const
    {
        return size == 0;
    }

    template <typename T>
    void VectorBase<T>:: clear()
    {
        size = 0;
    }

template <typename T>
void VectorBase<T>::swap(VectorBase<T>& v) {
        T* tempHead = head;
        unsigned int tempSize = size;
        unsigned int tempCapacity = capacity;

        head = v.head;
        size = v.size;
        capacity = v.capacity;

        v.head = tempHead;
        v.size = tempSize;
        v.capacity = tempCapacity;
    }

template <typename T>
void VectorBase<T>::reverse() {
        std::reverse(head, head + size);
    }
#endif
