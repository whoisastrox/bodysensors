#ifndef CLASS_LETTURA_H
#define CLASS_LETTURA_H

class lettura{

	double yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a;
	
	public:
	
	//metodi getter
	double get_yaw_v();
	double get_yaw_a();
	double get_pitch_v();
	double get_pitch_a();
	double get_roll_v();
	double get_roll_a();
	//metodi setter
	void set_yaw_v(const lettura&);
	void set_yaw_a(const lettura&);
	void set_pitch_v(const lettura&);
	void set_pitch_a(const lettura&);
	void set_roll_v(const lettura&);
	void set_roll_a(const lettura&);
	
	//costruttori
	lettura();
	lettura(double, double, double, double, double, double);
	//lettura(const lettura&); //costruttore di copia,  in realtà non è necessario perchè non ho allocazione dinamica della memoria, mi va bene la shallow copy
	//lettura& operator=(const lettura&); //assegnamento di copia, in realtà non è necessario perchè non ho allocazione dinamica della memoria, mi va bene la shallow copy
	

};


#endif
