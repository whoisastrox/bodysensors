#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <initializer_list>
#include <algorithm>
#include <iostream>
#include "../include/VECTOR_H.h"
using namespace std;

template <typename T>
vector<T>::vector(){ //di default crea un vector di dimensione 10
	vet=new T[10];
	vSize=0;
	maxSize=10;
	front=0;
	back=0;
	for(int i=0; i<maxSize; i++){
		vet[i]=T{}; //in questo modo chiama il costruttore di default per qualsiasi tipo di T venga usato
	}
}

template <typename T>
vector<T>::vector(int n){ //costruttore che definisce la dimensione del vector, explicit per disabilitare la conversione implicita
	vet=new T[n];
	vSize=0;
	maxSize=n;
	front=0;
	back=0;
	for(int i=0; i<maxSize; i++){
		vet[i]=T{};
	}
}

template <typename T>
vector<T>::vector(const vector<T>& v) //costruttore di copia
{
	vSize=v.size();
	front=v.front;
	back=v.back;
	vet=new T[vSize];
	copy(v.vet, v.vet+vSize, vet);
}
template <typename T>
vector<T>& vector<T>::operator=(const vector<T>& v){ //assegnamento di copia
	T *n=new T(v.size());
	
	copy(v.vet, v.vet+v.vSize, n);
	delete[] vet;
	vet=n;
	vSize=v.size();
	front=v.front;
	back=v.back;
	return *this;
}

template <typename T>
vector<T>::vector(vector<T>&& v): vSize{v.size()}, vet{v.vet}  //costruttore di spostamento, ruba il puntatore di v e invalida v
{
	v.vSize=0;  //invalido il vecchio oggetto
	v.vet=nullptr;
}

template <typename T>
vector<T>& vector<T>::operator=(vector<T>&& v) //assegnamento di spostamento
{
	delete[] vet; //elimino la vecchia area di memoria puntata da vet
	vet=v.vet;	//riassegno il puntatore
	front=v.front;	//riassegno gli indici
	back=v.back;	
	v.vet=nullptr;	//invalido il vecchio puntatore
	vSize=v.vSize;	
	v.vSize=0;		
	v.front=0;
	v.back=0;
	return *this;

}

template <typename T>
vector<T>::vector(std::initializer_list<T> lst): vSize{static_cast<int>(lst.size())}, vet{new T[lst.size()]}, front{0}, back{0} //faccio un cast sulla lunghezza dell'initializer list perchèè di tipo
											//long unsigned int e lo voglio assegnare ad un intero, è accettabile fare il cast in questo caso
{
	copy(lst.begin(), lst.end(), vet);
}

template <typename T>
int vector<T>::increment(int index){
        return (index+1)%maxSize;
}

template <typename T>
void vector<T>::push_back(T d){
	vet[back]=d;
	if(increment(back)==front){
		front=increment(front);
	}
	back=increment(back);
	if(vSize<maxSize)
		vSize++;
}


template <typename T>
T vector<T>::at(int i){
	if(i<vSize){
		return vet[i];
	}
	else{
		throw vector::vectorOutOfBounds();
	}
}
template <typename T>
T vector<T>::pop_front(){
	T ret=T{};
	if(!isEmpty()){
		ret=vet[front];
		vet[front]=T{};
		front=increment(front);
	}
	else{
		throw vector::vectorOutOfBounds();
	}
	vSize--;
	return ret;
	
	
}

template <typename T>
bool vector<T>::isEmpty() const{
	return front==back;
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
	if(i<maxSize){
		return vet[i]; //il dato ritornato punterà a vet[i], se la cella è vuota ritorna nullptr (le celle vuote contengono nullptr)
	}
	else{
		throw vector::vectorOutOfBounds();
	}
}

template <typename T>
T vector<T>::getFront()const{
	if(!isEmpty()){
		return vet[front];
	}
	else{
		throw vector::emptyQueueException();
	}
}

template <typename T>
T vector<T>::getBack() const{
	if(!isEmpty()){
		return vet[back-1];
	}
	else{
		throw vector::emptyQueueException();
	}
}






#endif

/*vector(const double[]){
	for(int i=0; i
}*/
