#include "../include/INERTIALDRIVER_H.h"
#include "../include/MEASURE_H.h"
#include "../include/READING_H.h"
int main(int argc, char* argv[]){
	
	reading r[17];
	r[0]=reading{1,2,3,4,5,6};
	r[1]=reading{1,2,3,4,5,6};
	r[2]=reading{1,2,3,4,5,6};
	r[3]=reading{1,2,3,4,5,6};
	r[4]=reading{1,2,3,4,5,6};
	r[5]=reading{1,2,3,4,5,6};
	r[6]=reading{1,2,3,4,5,6};
	r[7]=reading{1,2,3,4,5,6};
	r[8]=reading{1,2,3,4,5,6};
	r[9]=reading{1,2,3,4,5,6};
	r[10]=reading{1,2,3,4,5,6};
	r[12]=reading{1,2,3,4,5,6};
	r[13]=reading{1,2,3,4,5,6};
	r[14]=reading{1,2,3,4,5,6};
	r[15]=reading{1,2,3,4,5,6};
	r[16]=reading{1,2,3,4,5,6};
	r[17]=reading{1,2,3,4,5,6};
	Measure m=Measure{r};
	inertialDriver i=inertialDriver{50};
	
	i.push_back(m);
	
	std::cout<<i;
	
	
	

	
	return 0;}
