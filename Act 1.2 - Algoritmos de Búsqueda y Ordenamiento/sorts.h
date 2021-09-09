/*
sorts.h

ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include <list>
using namespace std;

template <class T>
class Sorts {

private:

	void mergeArray(vector<T>& A, vector<T>& B, int i, int j, int k);
	void copyArray(vector<T>& , vector<T>& , int , int );
    void mergeSplit(vector<T>& , vector<T>& , int , int );
	void swap(vector<T>&, int, int);

public:

	int busqBinaria(vector<T>&, int);
    int busqSecuencial(vector<T>&, int);
	void ordenaSeleccion(vector<T>&);
	void ordenaBurbuja(vector<T>&);
	void ordenaMerge(vector<T>&);

};

template <class T>
void Sorts<T>::swap(vector<T> &vc, int i, int j) {
	T aux = vc[i];
	vc[i] = vc[j];
	vc[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &vc) {
	int localizacion;

	for (int i = vc.size() - 1; i > 0; i--) {
		localizacion = 0;
		for (int j = 1; j <= i; j++) {
			if (vc[j] > vc[localizacion]) {
				localizacion = j;
			}
		}

		if (localizacion != i) {
			swap(vc, i, localizacion);
		}
	}
}


template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &vc) {

	for (int i = vc.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (vc[j] > vc[j + 1]) {
				swap(vc, j, j + 1);
			}
		}
	}
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &vc, int val) {
    for (int i = 0; i < vc.size(); i++) {
        if (val == vc[i])
            return i;
    }
    return -1;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &vc, int val) {
  ordenaSeleccion(vc);
    int centro;
    int menor = 0;
    int mayor = vc.size() - 1;

    while (mayor > menor) {
        centro = (mayor + menor) / 2;
        if (val == vc[centro]) {
            return centro;
        } else if (val < vc[centro]) {
            mayor = centro - 1;
        } else if (val > vc[centro]) {
            menor = centro + 1;
        }
    }
    return -1;
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T> &vc) {
    vector<T> aux(vc.size());

    mergeSplit(vc, aux, 0, vc.size() - 1);
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int menor, int mayor) {
    int centro;

    if ( (mayor - menor) < 1 ) {
        return;
    }
    centro = (mayor + menor) / 2;
    mergeSplit(A, B, menor, centro);
    mergeSplit(A, B, centro + 1, mayor);
    mergeArray(A, B, menor, centro, mayor);
    copyArray(A, B, menor, mayor);
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int menor, int centro, int mayor) {
    int i, j, k;

    i = menor;
    j = centro + 1;
    k = menor;

    while (i <= centro &&j <= mayor) {
        if (A[i] < A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if (i > centro) {
        for (; j <= mayor; j++) {
            B[k++] = A[j];
        }
    } else {
        for (; i <= centro; i++) {
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int menor, int mayor) {
    for (int i = menor; i <= mayor; i++) {
        A[i] = B[i];
    }
}


#endif /* SORTS_H_ */
