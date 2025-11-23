#ifndef VECTOR_H
#define VECTOR_H
#include <initializer_list>
using namespace std;
template <typename T>
class vector{

	T *vet=nullptr;
	int vSize;
	int maxSize;
	int front;
	int back;
	T* resize(int);
	
	public:
	class vectorOutOfBounds{};
	class emptyQueueException{};
	vector();
	//vector(const double[]);
	~vector();
	void push_back(T);
	T pop_front();
	T at(int);
	void reserve(int);
	int size() const;
	T& operator[](int); //ritorno reference così viene ritornato un riferimento alla cella del vettore che però viene dereferenziato automaticamente 
	//e mi permette di usare il valore come left value e modificare la cella
	vector(std::initializer_list<T>);
	vector(const vector<T>&); //costruttore di copia
	vector& operator=(const vector<T>&); //assegnamento di copia
	vector(vector<T>&&); //costruttore di spostamento, viene chiamato quando ritorno un oggetto da una funzione che anzichè copiare quell'oggetto e ritornarlo crea un nuovo oggetto che punta 
			//direttamente ai dati di quello vecchio
	vector<T>& operator=(vector<T>&&); //assegnamento di spostamento, viene chiamato quando dopo il ritorno di una funzione devo assegnare il ritorno ad un oggetto
	int increment(int); //per l'incremento degli indici front e back della coda
	bool isEmpty();
	T getFront();
	T getBack();
};

#include "VECTOR_HPP.hpp"
#endif
