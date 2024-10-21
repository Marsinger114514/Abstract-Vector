#ifndef VECTOR_H
#define VECTOR_H

#include "VectorBase.h"

template <typename T>
class Vector : public VectorBase<T> {
public:
	// 默认构造函数
	Vector() : VectorBase<T>() {}

	// 带容量参数的构造函数
	Vector(const unsigned int& s) : VectorBase<T>(s) {
		if (s > 0) {
			this->size = s;
		}
	}

	// 拷贝构造函数
	Vector(const Vector<T>& v) : VectorBase<T>(v) {}

	// 析构函数
	~Vector() {
		delete[] this->head;
	}

	// 运算符重载
	Vector<T>& operator=(const Vector<T>& v) {
		if (this == &v) {
			return *this;  // 检查是否自我赋值
		}

		// 释放当前对象的内存
		delete[] this->head;

		// 为新对象分配内存并深拷贝元素
		this->size = v.size;
		this->capacity = v.capacity;
		this->head = new T[this->capacity];

		// 复制元素
		for (unsigned int i = 0; i < this->size; ++i) {
			this->head[i] = v.head[i];
		}
		return *this;
	}

	Vector<T> operator+(const Vector<T>& v) {
		Vector<T> result(this->size + v.size);
		for (unsigned int i = 0; i < this->size; i++) {
			result.push_back(this->head[i]);
		}
		for (unsigned int i = 0; i < v.size; i++) {
			result.push_back(v.head[i]);
		}
		return result;
	}

	Vector<T>& operator+=(const Vector<T>& v) {
		for (unsigned int i = 0; i < v.size; i++) {
			this->push_back(v.head[i]);
		}
		return *this;
	}

	// 赋值函数
	void assign(const Vector<T>& v) {
		this->clear();
		for (unsigned int i = 0; i < v.size; i++) {
			this->push_back(v.head[i]);
		}
	}

	// 纯虚函数的实现
	void putout(ostream& out) const override {
		for (unsigned int i = 0; i < this->size; i++) {
			out << this->head[i] << " ";
		}
		out << std::endl;
	}

	void putin(istream& in) override {
		T value;
		while (in >> value) {
			this->push_back(value);
		}
	}
};

#endif
