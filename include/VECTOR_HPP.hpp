#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include "./VECTOR_H.h"
using namespace std;

template <typename T>
vector<T>::vector(){
	vet=new T[10];
	vSize=0;
	maxSize=10;
	for(int i=0; i<maxSize; i++){
		vet[i]=0;
	}
}
template <typename T>
vector<T>::vector(const vector<T>& v) //costruttore di copia
{
	vSize=v.size();
	vet=new T[vSize];
	copy(v.vet, v.vet+vSize, vet);
}
template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& v){
	T *n=new T(v.size());
	
	copy(v.vet, v.vet+v.vSize, n);
	delete[] vet;
	vet=n;
	vSize=v.size();
	return *this;
}

template <typename T>
vector<T>::vector(vector<T>&& v): vSize{v.size()}, vet{v.vet}
{
	v.vSize=0;  //invalido il vecchio oggetto
	v.vet=nullptr;
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& v) 
{
	delete[] vet;
	vet=v.vet;
	v.vet=nullptr;
	vSize=v.vSize;
	v.vSize=0;
	return *this;

}

template <typename T>
vector<T>::vector(std::initializer_list<T> lst): vSize{static_cast<int>(lst.size())}, vet{new T[lst.size()]} //faccio un cast sulla lunghezza dell'initializer list perchèè di tipo
											//long unsigned int e lo voglio assegnare ad un intero, è accettabile fare il cast in questo caso
{
	copy(lst.begin(), lst.end(), vet);
}

template <typename T>
void vector<T>::push_back(T d){
	if(vSize<maxSize){
		vet[vSize]=d;
		vSize++;
	}
	else{
		T* tmp=vet; //puntatore temporaneo per permettere poi di svuotare la memoria usata dal vecchio vet
		vet=resize(vSize*2);
		delete[] tmp;
		vet[vSize]=d;
		vSize++;
		
	}
}

template <typename T>
T* vector<T>::resize(int dim){
	T *tmp=new T[dim];
	for(int i=0; i<vSize; i++){
		tmp[i]=vet[i];
	}
	maxSize*=2;
	return tmp;
}

template <typename T>
T vector<T>::at(int i){
	if(i<vSize){
		return vet[i];
	}
	else{
		throw vector::outOfBound();
	}
}
template <typename T>
T vector<T>::pop_front(){
	/*double* tmp=vet;
	vet=&vet[1];
	double ret=*tmp;
	delete tmp;
	return ret;*/ 	//non fare così, se avanzo il puntatore al blocco di memoria allocato poi non posso più deallocarlo correttamente perchè non punta più al primo indirizzo
	if(vSize>0){
		T* tmp=vet;
		vet=new T[maxSize-1];
		maxSize--;
		for(int i=0; i<vSize-1; i++){
			vet[i]=tmp[i+1];
		}
		vSize--;
		T ret=*tmp;
		delete[] tmp;
		return ret;
	}
	else{
		throw vector::outOfBound();
	}
	
	
	
}
template <typename T>
void vector<T>::reserve(int n){
	T* tmp=vet;
	vet=resize(n);
	delete[] tmp;
}
template <typename T>
vector<T>::~vector(){
	delete[] vet;
}
template <typename T>
int vector<T>::size() const{
	return vSize;
}
template <typename T>
T& vector<T>::operator[](int i){
	if(i<vSize){
		return vet[i]; //il dato ritornato punterà a vet[i]
	}
	else{
		throw vector::outOfBound();
	}
}



#endif

/*vector(const double[]){
	for(int i=0; i
}*/
