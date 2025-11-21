#include <iostream>
#include "VECTOR_H.h"
using namespace std;
vector prova();
int main(){
	vector v{};
	for(int i=0; i<15; i++){
		v.push_back(i);
	}
	std::cout<<v[10];
	std::cout<<std::endl;
	v[10]=-1;
	std::cout<<v[10];
	std::cout<<std::endl;
	for(int i=0; i<15; i++){
		std::cout<<v.at(i)<<" ";
		
	}
	std::cout<<std::endl;
	for(int i=0; i<15; i++){
		std::cout<<v.pop_front()<<" ";
		
	}
	std::cout<<std::endl;
	std::cout<<v.size();
	cout<<endl;
	cout<<"----------------------------------------------"<<endl;
	vector v1{5,2.0,3.1};
	vector v2{3.1,3.1,3.1};
	for(int i=0; i<3; i++){
		std::cout<<v1.at(i)<<" ";
		
	}
	cout<<endl;
	cout<<"valore iniziale di v2[1] "<<v2[1]<<endl;
	
	v1=v2;  //ok, qui viene chiamato il costruttore di copia.
	v1[1]=0;
	cout<<"valore finale di v2[1] "<<v2[1]<<" invariato?"<<endl;
	for(int i=0; i<3; i++){
		std::cout<<v1.at(i)<<" ";
		
	}
	cout<<"dopo chiamata a funzione"<<endl;
	v1=prova(); //ok
	for(int i=0; i<3; i++){
		std::cout<<v1.at(i)<<" ";
	}
	return 0;
}

vector prova(){
	vector v2{3.1,3.1,3.1};
	return v2;
}





