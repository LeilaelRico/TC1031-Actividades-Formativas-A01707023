/*
heap.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T>
class Heap {

private:

    T *contenido;
	unsigned int tamanio;
	unsigned int cuentaEspacios;
	unsigned int raiz(unsigned int) const;
	unsigned int izquierda(unsigned int) const;
	unsigned int derecha(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);


public:

    Heap(unsigned int);
	~Heap();

    string toString() const;
    bool empty() const;
    void push(T);
    T pop();
    int size();
    int top();


};

/*******************************Privadas*******************************/

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T auxiliar = contenido[i];
	contenido[i] = contenido[j];
	contenido[j] = auxiliar;
}


template <class T>
void Heap<T>::heapify(unsigned int posicion) {
	unsigned int izq = izquierda(posicion);
	unsigned int der = derecha(posicion);
	unsigned int min = posicion;
	if (izq <= cuentaEspacios && contenido[izq] < contenido[min]) {
		min = izq;
	}
	if (der <= cuentaEspacios && contenido[der] < contenido[min]) {
		min = der;
	}
	if (min != posicion) {
		swap(posicion, min);
		heapify(min);
	}
}


template <class T>
unsigned int Heap<T>::raiz(unsigned int posicion) const {
	return (posicion - 1) / 2;
}


template <class T>
unsigned int Heap<T>::izquierda(unsigned int posicion) const {
	return ((2 * posicion) + 1);
}


template <class T>
unsigned int Heap<T>::derecha(unsigned int posicion) const {
	return ((2 * posicion) + 2);
}


/*******************************Públicas*******************************/

template <class T>
Heap<T>::Heap(unsigned int tam){
	tamanio = tam;
	contenido = new T[tamanio];
	cuentaEspacios = 0;
}


template <class T>
Heap<T>::~Heap() {
	delete [] contenido;
	contenido = 0;
	tamanio = 0;
	cuentaEspacios = 0;
}


template <class T>
bool Heap<T>::empty() const {
	return (cuentaEspacios == 0);
}


template <class T>
string Heap<T>::toString() const {
	stringstream auxiliar;
	auxiliar << "[";	for (unsigned int i = 0; i < cuentaEspacios; i++) {
		if (i != 0) {
			auxiliar << " ";
		} auxiliar << contenido[i];
	} auxiliar << "]";
	return auxiliar.str();
}


template <class T>
void Heap<T>::push(T val){
	unsigned int posicion;

	posicion = cuentaEspacios;
	cuentaEspacios++;
	while (posicion > 0 && val < contenido[raiz(posicion)]) {
		contenido[posicion] = contenido[raiz(posicion)];
		posicion = raiz(posicion);
	}
	contenido[posicion] = val;
}


template <class T>
T Heap<T>::pop(){
	if (empty()) {
		return -1;
	}
	T auxiliar = contenido[0];

	contenido[0] = contenido[--cuentaEspacios];
	heapify(0);
	return auxiliar;
}


template <class T>
int Heap<T>::size(){
    return cuentaEspacios;
}


template <class T>
int Heap<T>::top(){
    return contenido[0];
}


/*********************************************************/
#endif /* HASH_H_ */
