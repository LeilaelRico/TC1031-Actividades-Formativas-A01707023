/*
DList.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/


#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

using namespace std;

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}

/**Inicio clase listas**/

template <class T>

class DList {

public:

    DList();
    DList(const DList<T>&);
	~DList();

	string toStringForward() const;
	string toStringBackward() const;

	void insertion(T);
	int search(T);
	void update(int, T);
	T deleteAt(int);
	T    removeFirst();

private:

    DLink<T> *head;
    DLink<T> *tail;
    int size;

};


/**Constructores**/

template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

template <class T>
DList<T>::~DList() {
	DLink<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	size = 0;
}


template <class T>
void DList<T>::insertion(T valor){

    DLink<T> *newLink;

    newLink = new DLink<T>(valor);


    if (head == 0) {
        head = newLink;
        tail = newLink;
        size++;
        return;

	}else{

        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
	}
	size++;
}

template <class T>
int DList<T>::search(T valor){
    int pos;
    DLink<T> *p;

    p = head;
    pos = 0;

    while (p != 0) {

		if (p->value == valor){
            return pos;
		}
		p = p->next;
		pos++;
	}
	return -1;

}


template <class T>
void DList<T>::update(int posicion, T valor){
    int pos;
    DLink<T> *p;

    p = head;
    pos = 0;

    while (p != 0) {

        if (pos == posicion){
            p->value = valor;
            return;
        }
        p = p->next;
        //tail= p->next->next;
        pos++;
    }

}


template <class T>
T DList<T>::removeFirst(){
	T val;
	DLink<T> *p;

	p = head;
	val = p->value;

	if (head == tail) {
		head = 0;
		tail = 0;
	} else {
		head = p->next;
		p->next->previous = 0;
	}
	delete p;
	size--;

	return val;
}


template <class T>
T DList<T>::deleteAt(int posicion){
    int pos;
    T val;
    DLink<T> *p /*temp*/;

    if(posicion == 0){
        return removeFirst();
    }
    p = head;
    pos = 0;
    while (true) {

        if (pos == posicion){

            val = p->value;
            p->previous->next = p->next;
            //delete p;
            if (p->previous != 0){
                p->next->previous = p->previous;
            }
            break;
        }

        p = p->next;
        //temp = p;
        pos++;

    }
    size--;
    delete p;
    return val;
}


template <class T>
string DList<T>::toStringForward() const {
	stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}


template <class T>
string DList<T>::toStringBackward() const {
		stringstream aux;
		DLink<T> *p;
		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}


#endif
