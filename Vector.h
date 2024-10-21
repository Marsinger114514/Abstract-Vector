#ifndef VECTOR_H
#define VECTOR_H

#include "VectorBase.h"

template <typename T>
class Vector : public VectorBase<T> {
public:
	// Ĭ�Ϲ��캯��
	Vector() : VectorBase<T>() {}

	// �����������Ĺ��캯��
	Vector(const unsigned int& s) : VectorBase<T>(s) {
		if (s > 0) {
			this->size = s;
		}
	}

	// �������캯��
	Vector(const Vector<T>& v) : VectorBase<T>(v) {}

	// ��������
	~Vector() {
		delete[] this->head;
	}

	// ���������
	Vector<T>& operator=(const Vector<T>& v) {
		if (this == &v) {
			return *this;  // ����Ƿ����Ҹ�ֵ
		}

		// �ͷŵ�ǰ������ڴ�
		delete[] this->head;

		// Ϊ�¶�������ڴ沢���Ԫ��
		this->size = v.size;
		this->capacity = v.capacity;
		this->head = new T[this->capacity];

		// ����Ԫ��
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

	// ��ֵ����
	void assign(const Vector<T>& v) {
		this->clear();
		for (unsigned int i = 0; i < v.size; i++) {
			this->push_back(v.head[i]);
		}
	}

	// ���麯����ʵ��
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
