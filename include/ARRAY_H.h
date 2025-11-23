#ifndef ARRAY_H
#define ARRAY_H
using namespace std;

template<typename T, int N>
struct array {
    T elem[N];
    T& operator[] (int n);
    const T& operator[] (int n) const;
    T* data() { return elem; }
    const T* data() const { return elem; }
    int size() const { return N; }
};

#include "ARRAY_HPP.hpp"

#endif
