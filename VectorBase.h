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
    VectorBase() : head(nullptr), size(0), capacity(1024) {}    // 构造函数

    VectorBase(const VectorBase<T>& other) : size(other.size), capacity(other.capacity)     //深拷贝构造
    {
        head = new T[capacity];
        for (int i = 0; i < size; i++) {
            head[i] = other.head[i];
        }
    }
    // 添加新的构造函数，用于设置初始容量
    VectorBase(unsigned int initialCapacity) : head(nullptr), size(0), capacity(initialCapacity) {
        if (capacity > 0) {
            head = new T[capacity];
        }
    }
    virtual ~VectorBase()    // 析构函数
    {
        clear();
        delete[] head;
    }

    T& operator[](const unsigned int& pos) const;    // 返回下标为pos的元素
    bool operator==(const VectorBase<T>& v) const;    // 判断本向量和v是否相同
    bool operator!=(const VectorBase<T>& v) const;	//判断本向量和v是否不同
    unsigned int getsize()const;	//返回向量大小
    unsigned int getcapacity()const;	//返回向量容量
    void insert(const unsigned int&, const T&, const unsigned int&);	//在pos位置后插入n个元素val
    void erase(const unsigned int& pos);	//删除pos位置的一个元素
    void erase(const unsigned int& lt, const unsigned int& rt);	//删除从[left,right]闭区间内的所有元素。
    void push_back(const T &val);	//在尾部插入一个元素
    void pop_back();	//弹出尾部元素
    T back();	//返回尾部元素
    T& at(const unsigned int& pos);	//返回下标为pos的元素
    bool empty() const;	//判断向量是否为空
    void clear();	//清除向量所有元素
    void swap(VectorBase<T>& v);	//将本向量和v交换;
    void reverse();	//翻转向量
    virtual void putout(ostream& out) const = 0;    // 纯虚函数 putout
    virtual void putin(istream& in) = 0;    // 纯虚函数 putin

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
            throw std::out_of_range("位置超出范围");
        }
        if (size + n > capacity) {
            resize();
        }
        // 将元素向后移动n个位置
        for (unsigned int i = size; i > pos; --i) {
            head[i + n - 1] = head[i - 1];
        }
        // 在pos位置插入n个val元素
        for (unsigned int i = 0; i < n; ++i) {
            head[pos + i] = val;
        }
        size += n;
    }
template <typename T>
void VectorBase<T>::erase(const unsigned int& pos) {
    if (pos >= size) { // 注意：应该是 >= size 而不是 > size
        throw std::out_of_range("Index out of range");
    }
    std::move(head + pos + 1, head + size, head + pos); // 使用 std::move
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
