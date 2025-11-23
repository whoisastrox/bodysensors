#ifndef MEASURE_H
#define MEASURE_H

#include "READING_H.h"
#include "ARRAY_H.h"


class Measure {

    static const int MEASURE_SIZE = 17;

    reading m[MEASURE_SIZE];

    public:
        class fixedArrayOutOfBound{};
        Measure(reading[MEASURE_SIZE]);
        Measure();

        reading* toArray();

        reading& operator[](int i);
    
};


#endif

