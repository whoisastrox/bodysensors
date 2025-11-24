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

        inertialDriver(int dim=50);

        void push_back(const Measure& m); //memorizza misura nel buffer(sovrascrive la meno recente se è pieno)
        Measure pop_front(); //ritorna misura più vecchia e la rimuove
        void clear_buffer(); //elimina tutte le misure
        reading& get_reading(const int index); //ritorna la lettura della misura più recente corrispondente al numero passato
        int size() const { return buffer.size(); } //ritorna numero di misure presenti nel buffer
        bool isEmpty() const { return buffer.size() == 0; } //trona true se il buffer è vuoto
};

ostream& operator<<(ostream& out, const inertialDriver& driver); //overloading dell'operatore << per stampare ultima misura presente nel buffer

#endif

