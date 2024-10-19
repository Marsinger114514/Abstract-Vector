// DerivedString.h
#ifndef DERIVEDSTRING_H
#define DERIVEDSTRING_H

#include "VectorBase.h"
#include <string>

class DerivedString : public VectorBase<char> {
public:
    DerivedString() = default;
    ~DerivedString() override = default;

    // 实现纯虚函数 putout
    void putout(std::ostream& out) const override {
        for (unsigned int i = 0; i < this->size; ++i) {
            out << this->head[i];
        }
        out << std::endl;
    }

    // 实现纯虚函数 putin
    void putin(std::istream& in) override {
        std::string temp;
        in >> temp;
        for (char c : temp) {
            this->push_back(c);
        }
    }
};

#endif // DERIVEDSTRING_H