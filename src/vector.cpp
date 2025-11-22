#include "../include/VECTOR_H.h"
#include <initializer_list>
#include <algorithm>
#include <iostream>
using namespace std;

vector::vector(){
	vet=new double[10];
	vSize=0;
	maxSize=10;
	for(int i=0; i<maxSize; i++){
		vet[i]=0;
	}
}
vector::vector(const vector& v) //costruttore di copia
{
	vSize=v.size();
	vet=new double[vSize];
	copy(v.vet, v.vet+vSize, vet);
}
vector& vector::operator=(const vector& v){
	double *n=new double(v.size());
	
	copy(v.vet, v.vet+v.vSize, n);
	delete[] vet;
	vet=n;
	vSize=v.size();
	return *this;
}

vector::vector(vector&& v): vSize{v.size()}, vet{v.vet}
{
	v.vSize=0;  //invalido il vecchio oggetto
	v.vet=nullptr;
}

vector& vector::operator=(vector&& v) 
{
	delete[] vet;
	vet=v.vet;
	v.vet=nullptr;
	vSize=v.vSize;
	v.vSize=0;
	return *this;

}

vector::vector(std::initializer_list<double> lst): vSize{lst.size()}, vet{new double[lst.size()]}
{
	copy(lst.begin(), lst.end(), vet);
}

void vector::push_back(double d){
	if(vSize<maxSize){
		vet[vSize]=d;
		vSize++;
	}
	else{
		double* tmp=vet; //puntatore temporaneo per permettere poi di svuotare la memoria usata dal vecchio vet
		vet=resize(vSize*2);
		delete[] tmp;
		vet[vSize]=d;
		vSize++;
		
	}
}
double* vector::resize(int dim){
	double*tmp=new double[dim];
	for(int i=0; i<vSize; i++){
		tmp[i]=vet[i];
	}
	maxSize*=2;
	return tmp;
}
double vector::at(int i){
	if(i<vSize){
		return vet[i];
	}
	else{
		throw vector::outOfBound();
	}
}
double vector::pop_front(){
	/*double* tmp=vet;
	vet=&vet[1];
	double ret=*tmp;
	delete tmp;
	return ret;*/ 	//non fare così, se avanzo il puntatore al blocco di memoria allocato poi non posso più deallocarlo correttamente perchè non punta più al primo indirizzo
	if(vSize>0){
		double* tmp=vet;
		vet=new double[maxSize-1];
		maxSize--;
		for(int i=0; i<vSize-1; i++){
			vet[i]=tmp[i+1];
		}
		vSize--;
		double ret=*tmp;
		delete[] tmp;
		return ret;
	}
	else{
		throw vector::outOfBound();
	}
	
	
	
}
void vector::reserve(int n){
	double* tmp=vet;
	vet=resize(n);
	delete[] tmp;
}
vector::~vector(){
	delete[] vet;
}
int vector::size() const{
	return vSize;
}
double& vector::operator[](int i){
	if(i<vSize){
		return vet[i]; //il dato ritornato punterà a vet[i]
	}
	else{
		throw vector::outOfBound();
	}
}





/*vector(const double[]){
	for(int i=0; i
}*/
