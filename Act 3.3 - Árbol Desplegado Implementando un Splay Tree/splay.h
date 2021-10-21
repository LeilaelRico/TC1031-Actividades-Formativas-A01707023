/*
SplayTree.h
ITESM
Programación de Estructura de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa
A01707023
*/

#ifndef SPLAY_H_
#define SLAY_H_

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <class T> class SplayTree;


/*************************Clase Nodos*************************/


template <class T>
class Node {
private:
	T value;
	Node *left, *right, *parent;

	Node<T>* succesor();
	Node<T>* rRotation(Node<T>*);
	Node<T>* lRotation(Node<T>*);

public:
	Node(T);
	Node(T, Node<T>*, Node<T>* ,Node<T>*);
	Node<T>* add(T);
	Node<T>* find(T);
	Node<T>* remove(T);
	void removeChilds();
	void inorder(stringstream&) const;
	void print_tree(stringstream&) const;
	void preorder(stringstream&) const;
	Node<T>* splay(Node<T>*, Node<T>*);

	friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T valor) : value(valor), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T valor, Node<T> *le, Node<T> *ri, Node<T> *p)
	: value(valor), left(le), right(ri), parent(p) {}


template <class T>
Node<T>* Node<T>::add(T valor) {
	if (valor > value) {
		if (right == 0) {
                right = new Node<T>(valor);
                right->parent = this;
                return right;
		} else {
		    return right->add(valor);
		}
	} else {
		if (left == 0) {
                left = new Node<T>(valor);
                left->parent = this;
                return left;

		} else {
		    return left->add(valor);
		}
	}
}


template <class T>
Node<T>* Node<T>::find(T valor) {

	if (valor < value) {
		if (left == 0)
		 	return this;
		else
			return left->find(valor);
	} else if (valor > value) {
		if (right == 0)
		 	return this;
		else
			return right->find(valor);
	}else{
	    return this;
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
Node<T>* Node<T>::remove(T valor) {

	Node<T> *succ, *old;
	if (valor < value) {
		if (left != 0) {
			if (left->value == valor) {
				old = left;
				if(old->left != 0 && old->right != 0){
					succ = left->succesor();
					if (succ != 0) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					left = succ;
				} else if (old->right != 0){
					old->right->parent = left->parent;
					left = old->right;

				} else if (old->left != 0){
					old->left->parent = left->parent;
					left = old->left;
				} else {  // hoja
					left = 0;
				}
				delete old;
				return this;
			} else {
				return left->remove(valor);
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
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					right = succ;
				} else if (old->right != 0){
					old->right->parent = right->parent;
					right = old->right;

				} else if (old->left != 0){
					old->left->parent = right->parent;
					right = old->left;
				} else {
					right = 0;
				}
				delete old;
				return this;
			} else {
				return right->remove(valor);
			}
		}
	}
	return 0;
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
Node<T>* Node<T>::rRotation(Node<T>* x){
	Node<T> *y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->right = x;
	y->parent = x->parent;
	x->parent = y;
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Node<T>* Node<T>::lRotation(Node<T>* x){
	Node<T> *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->left = x;
	y->parent = x->parent;
	x->parent = y;
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
	while(x->parent != 0){

		if(x->parent->value == root->value){
			if(x->parent->left && x->parent->left->value == x->value){
				rRotation(x->parent);
			}else{
				lRotation(x->parent);
			}
		}else{
			Node<T>*p = x->parent;
			Node<T>*g = p->parent;
			if(p->left && g->left &&
				x->value == p->left->value && p->value == g->left->value){
				rRotation(g);
				rRotation(p);
			}else if(p->right && g->right &&
				x->value == p->right->value && p->value == g->right->value){
				lRotation(g);
				lRotation(p);
			}else	if(p->left && g->right &&
				x->value == p->left->value && p->value == g->right->value){
				rRotation(p);
				lRotation(g);
			}else{
				lRotation(p);
				rRotation(g);
			}
		}
	}
	return x;
}

template <class T>
void Node<T>::inorder(stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::print_tree(stringstream &aux) const {
	if (parent != 0){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != 0)
		aux << " left " << left->value;
	if (right != 0)
		aux << " right " << right->value;
	aux << "\n";

	if (left != 0) {
		left->print_tree(aux);
	}
	if (right != 0) {
		right->print_tree(aux);
	}
}

template <class T>
void Node<T>::preorder(stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}


/*************************Clase árboles*************************/


template <class T>
class SplayTree {
private:
	Node<T> *root;
	int total;

public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	void add(T);
	bool find(T);
	void remove(T);
	void removeAll();
	int size();

	string inorder() const;
	string print_tree() const;
	string preorder() const;
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {
    total = 0;
}

template <class T>
SplayTree<T>::~SplayTree() {
	removeAll();
	total = 0;
}

template <class T>
bool SplayTree<T>::empty() const {
	return (root == 0);
}

template<class T>
void SplayTree<T>::add(T valor) {

	if (root != 0) {
			Node<T>* added = root->add(valor);
			root = root->splay(root,added);
	} else {
		root = new Node<T>(valor);
	}
	total++;
}

template <class T>
void SplayTree<T>::remove(T valor) {
	if (root != 0) {
		if (valor == root->value) {
			Node<T> *succ = root->succesor();
			if (succ != 0) {
					succ->left = root->left;
					succ->right = root->right;
					succ->parent = 0;
					if(succ->left)
						succ->left->parent = succ;
					if(succ->right)
						succ->right->parent = succ;
			}
			delete root;
			root = succ;
		} else {
			Node<T>* p = root->remove(valor);
			root = root->splay(root,p);
		}
	}
	total--;
}

template <class T>
void SplayTree<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
	total = 0;
}

template <class T>
bool SplayTree<T>::find(T valor){
	if (root != 0) {
		Node<T>* found = root->find(valor);
		root = root->splay(root,found);
		return (root->value == valor);
	} else {
		return false;
	}
}


template <class T>
int SplayTree<T>::size(){
    return total;
}


template <class T>
string SplayTree<T>::inorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
string SplayTree<T>::print_tree() const {
	stringstream aux;

	aux << "\n ================================ ";
	if (!empty()) {
		root->print_tree(aux);
	}
	aux << " ================================ \n";
	return aux.str();
}



template <class T>
string SplayTree<T>::preorder() const {
	stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* SPLAY_H_ */
