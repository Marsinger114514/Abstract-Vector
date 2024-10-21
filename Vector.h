// vector.h
#ifndef VECTOR_H
#define VECTOR_H
#include "VectorBase.h" // 包含 VectorBase.h 头文件
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class Vector : public VectorBase<T> // 继承 VectorBase 类
{
public:
	Vector() : VectorBase<T>(), data(nullptr), size(0), capacity(4096) {} // 构造函数
	Vector(const int s) : VectorBase<T>(s), data(nullptr), size(0), capacity(s) {} // 构造函数
	Vector(const Vector<T>& vec) : VectorBase<T>(vec), size(vec.size), capacity(vec.capacity) { // 深拷贝构造函数
		data = new T[capacity];
		for (int i = 0; i < size; i++) {
			data[i] = vec.data[i];
		}
	}
	~Vector() {
		delete[] data;
	};
	Vector<T>& operator=(const Vector<T>& v);
	T& operator[](int pos) throw(int);
	const T& operator[](int pos) const throw(int);
	Vector<T>& operator+(const Vector<T>& v) throw(int);
	Vector<T>& operator+=(const Vector<T>& v) throw(int);
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const Vector<U>& v);
	void resize();
	void reverse();
	void input(); // 从文件内读取内容到容器
	void output(const string& filename); // 输出容器内数据到文件
	void push_back(const T val);
	void push_front(const T val);
	void insert(const T val, int pos);
	void insert(const T val, int pos, int n);
	void pop_back();
	void pop_front();
	void erase(const int pos) throw (int);
	void erase(const int lt, const int rt) throw (int);
	T& front();
	T& back();
	int getsize() const;
	int space() const;
	bool isempty() const;

	// 实现纯虚函数 putin
	void putin(istream& in) override {
		ifstream ifs("text.txt");
		if (!ifs) {
			cerr << "无法打开文件!" << endl;
			return;
		}
		T value;
		while (ifs >> value) {
			push_back(value); // 使用 push_back 添加到向量中
		}
		ifs.close();
	}

	// 实现纯虚函数 putout
	void putout(ostream& out) const override {
		for (int i = 0; i < this->getsize(); i++) {
			out << this->data[i] << ' ';
		}
	}

private:
	T *data;
	int size;
	int capacity;
};

template <typename T>
Vector<T>& Vector<T>:: operator=(const Vector<T>& v)
{
	if(this==&v) return *this;
	for(int i=0 ;i<v.getsize() ;i++)
	{
		data[i]=v[i];
	}
	return *this;
}

template <typename T>
T& Vector<T>:: operator[](int pos) throw (int)
{
	if(pos<0 || pos >= size) throw -1;                                 //下标越界，抛异常
	return data[pos];
}

template <typename T>
const T& Vector<T>::operator[](int pos) const throw(int) {
	if (pos < 0 || pos >= size) throw -1; // 下标越界，抛出异常
	return data[pos]; // 返回 const 引用，避免修改
}

template <typename T>
Vector<T>& Vector<T>:: operator+(const Vector<T>& v) throw(int)
{
	if(this->getsize()!=v.getsize()) throw -1;								//大小不同，抛异常
	for(int i=0 ;i<this->getsize() ;i++)
	{
		data[i] += v[i];													//每个元素相加
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>:: operator+=(const Vector<T>& v) throw(int)
{
	if(this->getsize() != v.getsize() ) throw -1;
	Vector<T> result(*this);
	for(int i=0 ;i<this->getsize() ;i++)
	{
		result[i] += v[i]; ;
	}
	return result;
}

template <typename T>
std::ostream & operator<<(std::ostream& out, const Vector<T>& v) {
    for (int i = 0; i < v.getsize(); i++) {
        out << v[i] << ' ';
    }
    return out;
}

template <typename T>
void Vector<T>:: resize()
{
	if(this->getsize()>=this->space() )
	{
		capacity *= 2;
        T* new_data = new T[capacity];
        for (int i = 0; i <size; i++)
		{
       		new_data[i] = data[i];												//把原数组中的每一项都都复制到新数组中
        }
        delete[] data;
        data = new_data;
	}
}

template <typename T>
void Vector<T>:: reverse()
{
	T temp;
	for(int i=0 ;i<size/2 ;i++)
	{
		temp = data[i];
		data[i] = data[size - 1 - i]; // 将当前元素与对称位置的元素交换
		data[size - 1 - i] = temp;
	}
}

template <typename T>
void Vector<T>:: push_back(const T val)
{
	resize();
	data[size] = val;
	size++;
}

template <typename T>
void Vector<T>:: push_front(const T val)
{
	resize();
	for(int i = size-1 ;i >= 0 ;i--)
	{
		data[i+1] = data[i];													//把每一个元素都向后移一位
	}
	data[0] = val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos)
{
	resize();
	for(int i=size-1 ;i>=pos-1 ;i--)
	{
		data[i+1]=data[i];
	}
	data[pos-1]=val;
	size++;
}

template <typename T>
void Vector<T>:: insert(const T val, int pos, int n)
{
	for(int i=0 ;i<n ;i++)
	{
		for(int j=size+i-1 ;j>=pos - 1 ;j--)
		{
			*(this+j+1)=*(this+j);
		}
	}
	for(int i=0 ;i<n ;i++)
	{
		*(this+pos-1+i)=val;
	}
	size+=n;
}

template <typename T>
void Vector<T>:: pop_back()
{
	size--;																			//容器大小-1，让所有操作都检索不到最后一项即可
}

template <typename T>
void Vector<T>:: pop_front()
{
	for(int i=1 ;i<size ;i++)
	{
		data[i-1]=data[i];														//所有项都向前移动一位
	}
	size--;
}

template <typename T>
void Vector<T>:: erase(const int pos) throw (int)
{
	if(pos<0 || pos>size) throw -1;
	for(int i=pos ;i<size ;i++)
	{
		data[i-1]=data[i];														//pos后的元素向前移动一位
	}
	size--;
}

template <typename T>
void Vector<T>:: erase(const int lt, const int rt) throw (int)
{
	if(lt<0 || lt>size || rt<0 || rt>size || lt>rt) throw -1;
	int n=rt-lt+1;
	for(int i=lt-1 ;i<size-n ;i++)
	{
		data[i]=data[i+n];														//rt后的元素向前移动n位
	}
	size-=n;
}

template <typename T>
T& Vector<T>:: front()
{
	return data[0];
}

template <typename T>
T& Vector<T>:: back()
{
	return data[size-1];
}

template <typename T>
int Vector<T>:: getsize() const
{
	return size;
}

template <typename T>
int Vector<T>:: space() const
{
	return capacity;
}

template <typename T>
bool Vector<T>:: isempty() const
{
	if(size==0) return true;
	return false;
}

template <typename T>
void Vector<T>::input() {
	ifstream ifs("text.txt");
	if (!ifs) {
		cout << "无法打开文件!" << endl;
		return;
	}

	T value;
	while (ifs >> value) {
		push_back(value); // 使用 push_back 添加到向量中
	}
	ifs.close();
}

template <typename T>
void Vector<T>::output(const string& filename) {
	ofstream ofs(filename, ios::out);
	if (!ofs) {
		cerr << "无法打开文件: " << filename << endl;
		return;
	}
	for (int i = 0; i < size; ++i) {
		ofs << data[i] << ' ';
	}
	ofs.close();
}

#endif