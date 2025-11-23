#include "../include/READING_H.h"

using namespace std;

string reading::print(const string sep){
    string s = "";
    return s 
            + to_string(yaw_v)
            + sep +
            to_string(yaw_a)
            + sep +
            to_string(pitch_v)
            + sep +
            to_string(pitch_a)
            + sep +
            to_string(roll_v)
            + sep +
            to_string(roll_a);
}