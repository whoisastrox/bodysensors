#include "ARRAY_H.h"

/*
    T elem[N];
    T& operator[] (int n);
    const T& operator[] (int n) const;
    T* data() { return elem; }
    const T* data() const { return elem; }
    int size() const { return N; }
*/

template<typename T, int N>
T& array<T, N>::operator[] (int n){
    
    if(i<N){
        return m[i];
    }else{
        throw 
    }
}

//TODO: inutile (?), finire di implementare se necessario