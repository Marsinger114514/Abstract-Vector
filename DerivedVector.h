// DerivedVector.h
#ifndef DERIVEDVECTOR_H
#define DERIVEDVECTOR_H

#include "VectorBase.h"

template <typename T>
class DerivedVector : public VectorBase<T> {
public:
    DerivedVector() = default;
    ~DerivedVector() override = default;

    // 实现纯虚函数 putout
    void putout(std::ostream& out) const override {
        for (unsigned int i = 0; i < this->size; ++i) {
            out << this->head[i] << " ";
        }
        out << std::endl;
    }

    // 实现纯虚函数 putin
    void putin(std::istream& in) override {
        T temp;
        while (in >> temp) {
            this->push_back(temp);
        }
    }
};

#endif // DERIVEDVECTOR_H