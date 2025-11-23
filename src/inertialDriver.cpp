#include "../include/INERTIALDRIVER_H.h"
#include "MEASURE_H.h"
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

reading& inertialDriver::get_reading(const int index){
    if(buffer.size()==0){throw emptyBuffer(); }
    if(index<0||index>=17){ throw invalidIndex(); }
    return buffer.getBack()[index];
}

ostream& operator<<(ostream& out, inertialDriver& driver){
    if(driver.isEmpty()){ return out << "Empty Buffer\n";}

    string s = "";
    for(int i = 0; i<17; i++){
        s += ((driver.get_reading(17).print("; ")) + "; ");
    }
    return out << s;
}

