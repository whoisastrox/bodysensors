#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "VECTOR_H.h"
#include "MEASURE_H.h"
#include <iostream>

using namespace std;

class inertialDriver{

    private:
        vector<Measure> buffer;
        int maxSize;
    
    public:
        class emptyBuffer{};
        class invalidIndex {};

        inertialDriver(int dim=8);

        void push_back(const Measure& m);
        Measure pop_front();
        void clear_buffer();
        const reading& get_reading(int index) const;
        int size() const { return buffer.size(); }
        bool empty() const { return buffer.size() == 0; }
};

#endif

