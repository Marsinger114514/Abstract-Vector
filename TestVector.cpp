#include <iostream>
#include "Vector.h"

int testVectorClass() {
    Vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    Vector<int> vec2;
    vec2.push_back(4);
    vec2.push_back(5);

    Vector<int> vec3 = vec1 + vec2;

    std::cout << "Vector 3: ";
    vec3.putout(std::cout);

    Vector<int> vec4;
    vec4.assign(vec3);
    std::cout << "Vector 4 (after assign): ";
    vec4.putout(std::cout);

    return 0;
}
