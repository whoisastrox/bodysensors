using namespace std;

#ifndef READING_H
#define READING_H

#include <string>


struct reading {
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;
    string print(const string);
};

#endif