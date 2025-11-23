#include "../include/INERTIALDRIVER_H.h"
#include <iostream>

inertialDriver::inertialDriver(int dim) : maxSize(dim) { buffer.reserve(maxSize);}

void inertialDriver::push_back(const Measure& m){
    if(buffer.size()==maxSize){ buffer.pop_front(); }
    buffer.push_back(m);
}

Measure inertialDriver::pop_front(){
    if(buffer.size()==0){ throw emptyBuffer(); }
    return buffer.pop_front();
}

void inertialDriver::clear_buffer(){
    while(buffer.size()>0){ buffer.pop_front(); }
}

const reading& inertialDriver::get_reading(int index) const {
    if(buffer.size()==0){throw emptyBuffer(); }
    if(index<0||index>=17){ throw invalidIndex(); }
    return buffer.getBack()[index];
}



