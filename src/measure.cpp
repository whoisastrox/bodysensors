#include "../include/MEASURE_H.h"

Measure::Measure(const reading rs[Measure::MEASURE_SIZE]): m{new reading[MEASURE_SIZE]} {
    std::copy(rs, rs+MEASURE_SIZE, m);
};

//costruttore di copia
Measure::Measure(const Measure& measure): m{new reading[MEASURE_SIZE]} {
    std::copy(measure.m, measure.m+MEASURE_SIZE, m);
};
//costruttore di default
Measure::Measure(): m{new reading[MEASURE_SIZE]} {
    std::fill(m, m+MEASURE_SIZE, (reading){0,0,0,0,0,0});
};

reading& Measure::operator[](int n){
    if(n>=MEASURE_SIZE || n < 0){
        throw arrayOutOfBound();
    }
    return m[n];
};

//assegnamento di copia
Measure& Measure::operator=(const Measure& measure){
    reading *p = new reading[MEASURE_SIZE];
    std::copy(measure.m, measure.m+MEASURE_SIZE, p);
    delete[] m;
    m=p;
    return *this;
};

//costruttore di spostamento
Measure::Measure(Measure&& measure): m{measure.m}{
    measure.m = nullptr;
}

//assegnamento di spostamento
Measure& Measure::operator=(Measure&& measure){
    delete[] m;
    m = measure.m;
    measure.m = nullptr;
    return *this;
}

string Measure::print(const string sep){
    string s = "";
    for(int i = 0; i<MEASURE_SIZE-1; i++){
        s += ((m[MEASURE_SIZE-1].print("; ")) + sep);
    }
    return s;
}