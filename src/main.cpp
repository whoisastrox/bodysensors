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
	r[11]=reading{1,2,3,4,5,6};
	r[12]=reading{1,2,3,4,5,6};
	r[13]=reading{1,2,3,4,5,6};
	r[14]=reading{1,2,3,4,5,6};
	r[15]=reading{1,2,3,4,5,6};
	r[16]=reading{1,2,3,4,5,6};
	Measure m=Measure{r};
	inertialDriver i=inertialDriver{50};
	//std::cout<<r[0].print(";");
	//std::cout<<m.print(";");
	i.push_back(m);
	reading r1[17];
	r1[0]=reading{7,8,9,10,11,12};
	r1[1]=reading{1,2,3,4,5,6};
	r1[2]=reading{1,2,3,4,5,6};
	r1[3]=reading{1,2,3,4,5,6};
	r1[4]=reading{1,2,3,4,5,6};
	r1[5]=reading{1,2,3,4,5,6};
	r1[6]=reading{1,2,3,4,5,6};
	r1[7]=reading{1,2,3,4,5,6};
	r1[8]=reading{1,2,3,4,5,6};
	r1[9]=reading{1,2,3,4,5,6};
	r1[10]=reading{1,2,3,4,5,6};
	r1[11]=reading{1,2,3,4,5,6};
	r1[12]=reading{1,2,3,4,5,6};
	r1[13]=reading{1,2,3,4,5,6};
	r1[14]=reading{1,2,3,4,5,6};
	r1[15]=reading{1,2,3,4,5,6};
	r1[16]=reading{1,2,3,4,5,6};
	Measure m1=Measure{r1};
	i.push_back(m1);

	std::cout<<"Misura dimensione buffer: "<<i.size()<<std::endl;
	std::cout<<i;
	
	i.pop_front();
	
	std::cout<<"stampa dopo il pop:"<<std::endl;
	std::cout<<"Misura dimensione buffer: "<<i.size()<<std::endl;
	std::cout<<i;
	
	i.pop_front();
	
	std::cout<<"stampa dopo il secondo pop:"<<std::endl;
	std::cout<<"Misura dimensione buffer: "<<i.size()<<std::endl;
	
	std::cout<<i;
	
	std::cout<<"Misura dimensione buffer: "<<i.size();
	
	//riempio nuovamente il buffer
	i.push_back(r);
	i.push_back(r1);
	std::cout<<"Misura dimensione buffer: "<<i.size()<<std::endl;
	i.clear_buffer();
	std::cout<<"Misura dimensione buffer dopo la pulizia: "<<i.size()<<std::endl;
	
	//provo a riempire il buffer completamente
	for(int k=0; k<70; k++){
		reading rk[17];
		for(int j=0; j<17; j++){
			rk[j]=reading{static_cast<double>(k),static_cast<double>(k),static_cast<double>(k),static_cast<double>(k),static_cast<double>(k),static_cast<double>(k)};
		}
		i.push_back(rk);
	}
	
	std::cout<<"Misura dimensione buffer post riempimento: "<<i.size()<<std::endl;
	for(int k=0; k<50; k++){
		std::cout<<k<<": "<<i.size();
		i.pop_front();
		
	}
	std::cout<<"Misura dimensione buffer dopo la pulizia: "<<i.size()<<std::endl;
	
	
	
	

	
	return 0;}
