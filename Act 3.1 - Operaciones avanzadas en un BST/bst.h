/*
bst.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T> class BST;


/*************************Clase Nodos*************************/


template <class T>
class Node {
private:
	T value;
	Node *left, *right;
	int nivel, balance;

	Node<T>* succesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(stringstream&) const;
	void preorder(stringstream&) const;
	void postorder(stringstream&) const;
	void LbyL(stringstream&) const;
	int height();

	void ancestors(stringstream&, T) const;
	int whatlevelamI(T);

	friend class BST<T>;
};

template <class T>
Node<T>::Node(T valor) : value(valor), left(0), right(0) {}

template <class T>
Node<T>::Node(T valor, Node<T> *le, Node<T> *ri)
	: value(valor), left(le), right(ri) {}

template <class T>
void Node<T>::add(T valor) {
	if (valor < value) {
		if (left != 0) {
			left->add(valor);
		} else {
			left = new Node<T>(valor);
		}
	} else {
		if (right != 0) {
			right->add(valor);
		} else {
			right = new Node<T>(valor);
		}
	}
}

template <class T>
bool Node<T>::find(T valor) {
	if (valor == value) {
		return true;
	} else if (valor < value) {
		return (left != 0 && left->find(valor));
	} else if (valor > value) {
		return (right != 0 && right->find(valor));
	}
}

template <class T>
Node<T>* Node<T>::succesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (right->left == 0) {
		right = right->right;
		ri->right = 0;
		return ri;
	}

	Node<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != 0) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = 0;
	return child;
}

template <class T>
void Node<T>::remove(T valor) {
	Node<T> * succ, *old;

	if (valor < value) {
		if (left != 0) {
			if (left->value == valor) {
				old = left;
				if(old->left != 0 && old->right != 0){
					succ = left->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
					}
					left = succ;
				} else if (old->right != 0){
						left = old->right;
				} else if (old->left != 0){
						left = old->left;
				} else {
						left = 0;
				}
				delete old;
			} else {
				left->remove(valor);
			}
		}
	} else if (valor > value) {
		if (right != 0) {
			if (right->value == valor) {
				old = right;
				if(old->left != 0 && old->right != 0){
					succ = right->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
					}
					right = succ;
				} else if (old->right != 0){
					right = old->right;
				} else if (old->left != 0){
					right = old->left;
				} else {  // hoja
					right = 0;
				}
					delete old;
			} else {
				right->remove(valor);
			}
		}
	}
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

template <class T>
void Node<T>::inorder(stringstream &auxiliar) const{
	if (left != 0) {
		left->inorder(auxiliar);
	}
	if (auxiliar.tellp() != 1) {
		auxiliar << " ";
	}
	auxiliar << value;
	if (right != 0) {
		right->inorder(auxiliar);
	}
}

template <class T>
void Node<T>::preorder(stringstream &auxiliar) const{
	auxiliar << value;
	if (left != 0) {
		auxiliar << " ";
		left->preorder(auxiliar);
	}
	if (right != 0) {
		auxiliar << " ";
		right->preorder(auxiliar);
	}
}

template <class T>
void Node<T>::postorder(stringstream &auxiliar) const{

	if (left != 0) {
		left->postorder(auxiliar);
		auxiliar << " ";
	}
	if (right != 0) {
		right->postorder(auxiliar);
		auxiliar << " ";
	}
	auxiliar << value;
}

template <class T>
void Node<T>::LbyL(stringstream &auxiliar) const{

	auxiliar << value;
	if (left != 0) {
		auxiliar << " ";
		left->LbyL(auxiliar);
	}
	if (right != 0) {
		auxiliar << " ";
		right->LbyL(auxiliar);
	}
}

template <class T>
int Node<T>::height() {
    int le =0 , ri = 0;
    if (left != 0)
        le = left->height() + 1;
    if (right != 0)
        ri = right->height() + 1;
    if(le > ri)
        nivel = le;
    else
        nivel = ri;
    balance = le - ri;
    return nivel;
}


template <class T>
void Node<T>::ancestors(stringstream &aux, T valor) const{


    /*if (aux.tellp() != 1) {
        aux << " ";
        }*/

    if (left != 0 && valor < value) {

        if (aux.tellp() != 1 && valor != value) {
        aux << " ";
        }

        aux << value;
        left->ancestors(aux, valor);

    }
    if (right != 0 && valor > value) {

        if (aux.tellp() != 1 && valor != value) {
        aux << " ";
        }

        aux << value;
        right->ancestors(aux, valor);
    }
}


template <class T>
int Node<T>::whatlevelamI(T valor){
    int le =0 , ri = 0;
    if (left != 0 && valor < value)
        le = left->whatlevelamI(valor) + 1;
    if (right != 0 && valor > value)
        ri = right->whatlevelamI(valor) + 1;
    if(le > ri)
        nivel = le;
    else
        nivel = ri;
    balance = le - ri;
    return nivel;
}

/*************************Clase árboles*************************/


template <class T>
class BST {
private:
	Node<T> *root;

public:
	BST();

	bool empty() const;
	bool find(T) const;

	void add(T);
	string visit();
    int height ();
    string ancestors(T) const;
    int whatlevelamI(int);

    string preorder() const;
    string inorder() const;
	string postorder() const;
	string LbyL() const;


};

template <class T>
bool BST<T>::find(T valor) const {
	if (root != 0) {
		return root->find(valor);
	} else {
		return false;
	}
}


template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template <class T>
BST<T>::BST() : root(0) {}

template<class T>
void BST<T>::add(T valor) {
	if (root != 0) {
		if (!root->find(valor)) {
			root->add(valor);
		}
	} else {
		root = new Node<T>(valor);
	}
}

template <class T>
string BST<T>::preorder() const {
	stringstream auxiliar;

	auxiliar << "[";
	if (!empty()) {
		root->preorder(auxiliar);
	}
	auxiliar << "]";
	return auxiliar.str();
}


template <class T>
string BST<T>::inorder() const {
	stringstream auxiliar;

	auxiliar << "[";
	if (!empty()) {
		root->inorder(auxiliar);
	}
	auxiliar << "]";
	return auxiliar.str();
}

template <class T>
string BST<T>::postorder() const {
	stringstream auxiliar;

	auxiliar << "[";
	if (!empty()) {
		root->postorder(auxiliar);
	}
	auxiliar << "]";
	return auxiliar.str();
}

template <class T>
string BST<T>::LbyL() const {
	stringstream auxiliar;

	auxiliar << "[";
	if (!empty()) {
		root->LbyL(auxiliar);
	}
	auxiliar << "]";
	return auxiliar.str();
}

template <class T>
string BST<T>::visit(){
    stringstream auxiliar;

    auxiliar<<preorder()<<"\n";
    auxiliar<<inorder()<<"\n";
    auxiliar<<postorder()<<"\n";
    auxiliar<<LbyL();

    return auxiliar.str();

}

template <class T>
int BST<T>::height(){

    return root->height()+1;
}


template <class T>
string BST<T>::ancestors(T valor) const {
	stringstream auxiliar;

	auxiliar << "[";
	if (!empty()) {
        if(root->find(valor))
        root->ancestors(auxiliar, valor);
    }
	auxiliar << "]";
	return auxiliar.str();
}


template <class T>
int BST<T>::whatlevelamI(int n){

    return root->whatlevelamI(n)+1;
}


#endif /* BST_H_ */
