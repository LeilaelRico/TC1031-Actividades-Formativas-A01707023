/*
list.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/


#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>

using namespace std;

template <class T> class List;

template <class T>
class Link {
private:

	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
};

/***Funciones Link***/

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

/**Inicio clase listas**/

template <class T>

class List {

public:

    List();
    List(const List<T>&);
	~List();

	string toString() const;

	void insertion(T);
	int search(T);
	void update(int, T);
	T deleteAt(int);

private:

    Link<T> *head;
    int size;

};

/**Constructores**/

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

template <class T>
void List<T>::insertion(T valor){

    Link<T> *newLink, *p;

    newLink = new Link<T>(valor);


    if (head == 0) {
        newLink->next = head;
        head = newLink;
        size++;
        return;
	}

    p = head;
    while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
    size++;
}

template <class T>
int List<T>::search(T valor){
    int pos;
    Link<T> *p;

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
void List<T>::update(int posicion, T valor){
    int pos;
    Link<T> *p;

    p = head;
    pos = 0;

    while (p != 0) {

		if (pos == posicion){
            p->value = valor;
            return;
		}
		p = p->next;
		pos++;
	}

}

template <class T>
T List<T>::deleteAt(int posicion){
    T val;
    Link<T> *p, *temp;
    p = head;
    int pos=1; // Ya que para eliminar el valor inicial hay un if.
    temp = p->next;

    if (posicion == 0){
            head = p->next;
            delete p;
            return val;
    }else{

        while (true) {

            if (pos == posicion){

                val = temp->value;
                p->next = temp->next;
                delete p;
                break;
            }

            p = p->next;
            temp = p;
            pos++;

        }
    }
    return val;
}

template <class T>
string List<T>::toString() const {
	stringstream aux;
	Link<T> *p;

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
#endif
