/*
 * AVL.h
 *
 *  Created on: 11/10/2021
 *      Author: bvaldesa
 */

#ifndef AVL_H_
#define AVL_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

using namespace std;

template <class T> class AVL;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;
	int level, balance;
	Node<T>* predecesor();

public:
	Node(T);
	Node(T, Node<T>*, Node<T>*, int, int);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	int max_depth();
	Node<T>* check_tree(T*, Node<T>*, bool*);
	Node<T>* balance_tree();
	Node<T>* rot_left(Node<T>* );
	Node<T>* rot_right(Node<T>* );
	Node<T>* rot_left_right(Node<T>* );
	Node<T>* rot_right_left(Node<T>* );
	friend class AVL<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), level(0), balance(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, int lev, int bal)
	: value(val), left(le), right(ri), level(lev), balance(bal) {}

template <class T>
void Node<T>::add(T val) {
	if (val < value) {
		if (left != 0) {
			left->add(val);
		} else {
			left = new Node<T>(val);
		}
	} else {
		if (right != 0) {
			right->add(val);
		} else {
			right = new Node<T>(val);
		}
	}
}

template <class T>
bool Node<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != 0 && left->find(val));
	} else if (val > value) {
		return (right != 0 && right->find(val));
	}
}

template <class T>
Node<T>* Node<T>::predecesor() {
	Node<T> *le, *ri;

	le = left;
	ri = right;

	if (left == 0) {
		if (right != 0) {
			right = 0;
		}
		return ri;
	}

	if (left->right == 0) {
		left = left->left;
		le->left = 0;
		return le;
	}

	Node<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != 0) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = 0;
	return child;
}

template <class T>
void Node<T>::remove(T val) {
	Node<T> * succ, *old;

	if (val < value) {
		if (left != 0) {
			if (left->value == val) {
				old = left;
				succ = left->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != 0) {
			if (right->value == val) {
				old = right;
				succ = right->predecesor();
				if (succ != 0) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
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
void Node<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << "(" << value << " " << level << " " << balance << ")";
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
	aux << "(" << value << " " << level << " " << balance << ")";
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
int Node<T>::max_depth() {
	int le =0 , ri = 0;
	if (left != 0)
		le = left->max_depth() + 1;
	if (right != 0)
		ri = right->max_depth() + 1;
	if(le > ri)
		level = le;
	else
		level = ri;
	balance = le - ri;
	return level;
}

//checar si el arbol esta balanceado, identificar en que nodo rotar, rotar una vex, 'a' regresa el nodo padre nuevo
template <class T>
Node<T>* Node<T>::check_tree(T *check_val, Node<T> *parent, bool *checked) {
	cout<< "node value " << value <<" "<< level <<" "<< balance << endl;
	Node<T>*le = 0, *ri = 0, *a = 0;
	if (left != 0)
		le = left->check_tree(check_val,this,checked);
	if (right != 0)
		ri = right->check_tree(check_val,this,checked);
	if (*checked == false){
		if (balance > 1){
			a = balance_tree();
			*check_val = value;
			*checked = true;
			if(parent != 0){
				cout<< "parent  " << parent->value <<" parent->left "<< parent->left->value<< endl;
				parent->left = a;
			}
		}else if (balance < -1){
			a = balance_tree();
			*check_val = value;
			*checked = true;
			if(parent != 0){
				cout<< "parent  " << parent->value <<" parent->right "<< parent->right->value<< endl;
				parent->right = a;
			}
		}
	}
	return a;
}

template <class T>
Node<T>* Node<T>::balance_tree() {
	Node<T> *a = this, *le =left, *ri =right;
	int old_value = value;
	cout<< "Balancing node : " << a->value << " " << endl;
	if (balance > 0) {
		if (le->balance > 0){
			cout<< "rot_right  " << a->balance << " left: " << le->balance << endl;
			a = rot_right(a);
		}else{
			cout<< "rot_left_right " << a->balance << " left: " << le->balance << endl;
			a = rot_left_right(a);
		}
	}else{
		if (ri->balance < 0){
			cout<< "rot_left " << a->balance << " right: " << ri->balance << endl;
			a = rot_left(a);
		}else{
			cout<< "rot_right_left " << a->balance << " right: " << ri->balance << endl;
			a = rot_right_left(a);
		}
	}
	cout<< "New current node value is " << a->value << endl;
	return a;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* a){
	Node<T> *b, *temp = 0;
	if (a->right != 0){
		b = a->right;
		if (b->left != 0)
			temp = b->left;
		b->left = a;
		if(temp != 0){
			a->right = temp;
		}else{
			a->right = 0;
		}
	}
	return b;
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* a){
	Node<T> *b, *temp = 0;
	if (a->left != 0){
		b = a->left;
		if (b->right != 0)
			temp = b->right;
		b->right = a;
		if(temp != 0){
			a->left = temp;
		}else{
			a->left = 0;
		}
	}
	return b;
}

template <class T>
Node<T>* Node<T>::rot_left_right(Node<T>* a){
	a->left = rot_left(a->left);
	a = rot_right(a);
	return a;
}

template <class T>
Node<T>*  Node<T>::rot_right_left(Node<T>* a){
	a->right = rot_right(a->right);
	a = rot_left(a);
	return a;
}

template <class T>
class AVL {
private:
	Node<T> *root;

public:
	AVL();
	~AVL();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string preorder() const;
};

template <class T>
AVL<T>::AVL() : root(0) {}

template <class T>
AVL<T>::~AVL() {
	removeAll();
}

template <class T>
bool AVL<T>::empty() const {
	return (root == 0);
}

template<class T>
void AVL<T>::add(T val) {
	if (root != 0) {
		if (!root->find(val)) {
			Node <T> *temp;
			T check_val = false;
			bool aux = false;
			root->add(val);
			root->max_depth();
			temp = root->check_tree(&check_val, 0, &aux);
			if (check_val == root->value){
				root = temp;
			}
			root->max_depth();
		}
	} else {
		root = new Node<T>(val);
	}
}

template <class T>
void AVL<T>::remove(T val) {
	if (root != 0) {
		if (val == root->value) {
			Node<T> *succ = root->predecesor();
			if (succ != 0) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
		root->max_depth();
		Node <T> *temp;
		T check_val = false;
		bool aux = false;
		temp = root->check_tree(&check_val, 0, &aux);
		if (check_val == root->value){
			root = temp;
		}
		root->max_depth();
	}
}

template <class T>
void AVL<T>::removeAll() {
	if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

template <class T>
bool AVL<T>::find(T val) const {
	if (root != 0) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
std::string AVL<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string AVL<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* AVL_H_ */
