#include "../include/INERTIALDRIVER_H.h"
#include "../include/MEASURE_H.h"
#include <iostream>

//Imposta dimensione massima del buffer
inertialDriver::inertialDriver(int dim) : maxSize(dim) {} 

//Inserisce nuova misura nel buffer
void inertialDriver::push_back(const Measure& m){ 
    if(buffer.size()==maxSize){ buffer.pop_front(); }
    buffer.push_back(m);
}

//Ritorna misura più vecchia e la rimuove
Measure inertialDriver::pop_front(){
    if(buffer.size()==0){ throw emptyBuffer(); }
    return buffer.pop_front();
}

//Elimina tutte le misure presenti nel buffer
void inertialDriver::clear_buffer(){
    while(buffer.size()>0){ buffer.pop_front(); }
}

//Ritorna lettura della misura più recente
reading& inertialDriver::get_reading(const int index){
    if(buffer.size()==0){throw emptyBuffer(); }
    if(index<0||index>=17){ throw invalidIndex(); }
    return buffer.getBack()[index];
}

//Stampa ultima misura presente del buffer
ostream& operator<<(ostream& out, inertialDriver& driver){
    if(driver.isEmpty()){ return out << "Empty Buffer\n";}

    string s = "";
    for(int i = 0; i<17; i++){
        s += ((driver.get_reading(17).print("; ")) + "; ");
    }
    return out << s;
}

