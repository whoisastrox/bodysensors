#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "READING_H.h"
#include "ARRAY_H.h"


class Measure {

    static const int MEASURE_SIZE = 17;

    array<reading, MEASURE_SIZE> m;


    public:
        class fixedArrayOutOfBound{};
        Measure(array<reading, MEASURE_SIZE> rs);
        Measure();

        array<reading, MEASURE_SIZE> toArray(){}

        reading& operator[](int i);
    
};


#endif

