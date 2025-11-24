#include "CLASS_LETTURA_H.h"
//costruttori:

lettura::lettura(): yaw_v{0}, yaw_a{0}, pitch_v{0}, pitch_a{0}, roll_v{0}, roll_a{0}
{}
lettura::lettura(double yaw_v, double yaw_a, double pitch_v, double pitch_a, double roll_v, double roll_a){
	this->yaw_v=yaw_v;
	this->yaw_a=yaw_v;
	this->pitch_a=pitch_a;
	this->pitch_v=pitch_v;
	this->roll_v=roll_v;
	this->roll_a=roll_a;
}

//metodi getter
double lettura::get_yaw_v(){
	return yaw_v;
}
double lettura::get_yaw_a(){
	return yaw_a;
}
double lettura::get_pitch_v(){
	return pitch_v;
}
double lettura::get_pitch_a(){
	return pitch_a;
}
double lettura::get_roll_v(){
	return roll_v;
}
double lettura::get_roll_a(){
	return roll_a;
}
//metodi setter
void lettura::set_yaw_v(const lettura& l){
	yaw_v=l.yaw_v;
}
void lettura::set_yaw_a(const lettura& l){
	yaw_a=l.yaw_a;
}
void lettura::set_pitch_v(const lettura& l){
	pitch_v=l.pitch_v;
}
void lettura::set_pitch_a(const lettura& l){
	pitch_a=l.pitch_a;
}
void lettura::set_roll_v(const lettura& l){
	roll_v=l.roll_v;
}
void lettura::set_roll_a(const lettura& l){
	roll_a=l.roll_a;
}
