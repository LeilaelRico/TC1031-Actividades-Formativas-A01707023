/*
quadratic.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef QUADRATIC_H_
#define QUADRATIC_H_

#include <string>
#include <sstream>
using namespace std;

template <class Key, class Value>
class Quadratic {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	Quadratic(unsigned int, Key, unsigned int (*f) (const Key));
	~Quadratic();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key);
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f) (const Key)) {
	size = sze;
	keys = new Key[size];
	if (keys == 0) {
        //Coso
        cout << "Out of Memory" << endl;
    }
	initialValue = init;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = init;
	}
	values = new Value[size];
	if (values == 0) {

        cout << "Out of Memory" << endl;

    }
	for (int i = 0; i  < sze; i++){
        values[i] = 0;
    }

	func = f;
	count = 0;
}

template <class Key, class Value>
Quadratic<Key, Value>::~Quadratic() {
	delete [] keys;
	keys = 0;
	delete [] values;
	values = 0;
	size = 0;
	func = 0;
	count = 0;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::full() const {
	return (count > size);
}

template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key ky) const {
	unsigned int i, start;

	start = i = func(ky) % size;
	do {
		if (keys[i] == ky) {
			return i;
		}
		i = (i + 1) % size;
	} while (start != i);
	return -1;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key ky, Value val){
	unsigned int i, start;
	long pos;

	if (full()) {

        return false;

	}

	pos = indexOf(ky);
	if (pos != -1) {

		values[pos] = val;
		return true;

	}

	start = i = func(ky) % size;

	do {

		if (keys[i] == initialValue) {

			keys[i] = ky;
			values[i] = val;		
			return true;

		}

		count++;
		i = (i+(count*count)) % size;
		

	} while (start != i);

	return false;
}

template <class Key, class Value>
bool Quadratic<Key, Value>::contains(const Key ky) const {
	long pos;

	pos = indexOf(ky);
	return (pos != -1);
}

template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key ky){
	unsigned int i, start;
	long pos;

	pos = indexOf(ky);
	if (pos != -1) {
		return values[pos];
	}
	cout << "Out of Memory" << endl;
}

template <class Key, class Value>
void Quadratic<Key, Value>::clear() {
	count = 0;
	for (unsigned int i = 0; i < size; i++) {
		keys[i] = initialValue;
	}
}

template <class Key, class Value>
std::string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;
	for (int i = 0; i < size; i++){
			if (keys[i] != initialValue){
				aux << "(" << i << " ";
			  aux << keys[i] << " : " << values[i] << ") ";
			}
	}
	return aux.str();
}
#endif /* Quadratic */