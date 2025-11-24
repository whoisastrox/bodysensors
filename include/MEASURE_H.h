#ifndef MEASURE_H
#define MEASURE_H

#include "READING_H.h"
#include <string>

class Measure {

    static const int MEASURE_SIZE = 17;

    reading *m = nullptr;

    public:
        class arrayOutOfBound{};
        Measure(const reading[MEASURE_SIZE]);
        Measure(const Measure&);
        Measure();
        
        //reading* toArray();

        
        reading& operator[](int i);
        Measure& operator=(const Measure&);

        Measure(Measure&&); // move constructor
        Measure& operator=(Measure&&);

        string print(const string sep) const;
    
};


#endif

