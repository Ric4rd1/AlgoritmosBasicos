/*
 * splay.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 */

#ifndef Splay_H_
#define Splay_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

using namespace std;

template <class T>class SplayTree;

template <class T>
class Node {
private:
	T value;
	Node *left, *right;
public:
	Node(T val) : value(val), left(0), right(0) {}
	Node(T val, Node<T> *le, Node<T> *ri)
		: value(val), left(le), right(ri) {}
	friend class SplayTree<T>;
};

template <class T>
class SplayTree {
public:
	SplayTree(){}
	Node<T>* rot_right(Node<T>*);
	Node<T>* rot_left(Node<T>*);
	Node<T>* splay(T, Node<T>*);
	Node<T>* new_node(T);
	Node<T>* add(T, Node<T>*);
	Node<T>* remove(T, Node<T>*);
	Node<T>* find(T, Node<T>*);
	void inorder(Node<T>*);
	void preorder(Node<T>*);
};

template <class T>
Node<T>* SplayTree<T>::rot_right(Node<T>* x){
	Node<T> *y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

template <class T>
Node<T>* SplayTree<T>::rot_left(Node<T>* x){
	Node<T> *y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

template <class T>
Node<T>* SplayTree<T>::splay(T val, Node<T>* root){
	if(root == NULL)
		return NULL;

	Node<T> temp(0);
	temp.left = NULL;
	temp.right = NULL;

	Node<T>* left_sub_tree = &temp;
	Node<T>* right_sub_tree = &temp;

	while(1){
		if(val < root->value){
			if(root->left == NULL)
				break;
			if(val < root->left->value){
				root = rot_right(root);
				if(root->left == NULL)
					break;
			}
			/*se recorren los nodos,
			right_sub_tree pasa a apuntar al nodo de root por su left
			y root pasa a apuntar a su hijo left*/
			right_sub_tree->left = root;
			right_sub_tree = right_sub_tree->left;
			root = root->left;
			right_sub_tree->left = NULL;
		}else if(val > root->value){
			if(root->right == NULL)
				break;
			if(val > root->right->value){
				root = rot_left(root);
				if(root == NULL)
					break;
			}
			/*se recorren los nodos,
			left_sub_tree pasa a apuntar al nodo de root por su right
			y root pasa a apuntar a su hijo right*/
			left_sub_tree->right = root;
			left_sub_tree = left_sub_tree->right;
			root = root->right;
			left_sub_tree->right = NULL;
		}
		else
			break;
	}
	/*Pegamos ambos lados del arbol:
	left_sub_tree y right_sub_tree al nuevo root
	primero ponemos los sub arboles que quedaron volando o pendientes*/
	left_sub_tree->right = root->left;
	right_sub_tree->left = root->right;
	root->left = temp.right;
	root->right = temp.left;

	if(left_sub_tree){
		if(left_sub_tree->left)cout<< "left_sub_tree left " << left_sub_tree->left->value << endl;
		if(left_sub_tree->right)cout<< "left_sub_tree right " << left_sub_tree->right->value << endl;
	}
	if(right_sub_tree){
		if(right_sub_tree->left)cout<< "right_sub_tree left " << right_sub_tree->left->value << endl;
		if(right_sub_tree->right)cout<< "right_sub_tree right " << right_sub_tree->right->value << endl;
	}
	if(temp.left)cout<< "temp left " << temp.left->value << endl;
	if(temp.right)cout<< "temp right " << temp.right->value << endl;
	cout<< "root value " << root->value << endl << endl;

	return root;
}

template <class T>
Node<T>* SplayTree<T>::new_node(T val){
	Node<T>* p_node = new Node<T>(val);
	if(p_node == NULL)
	{
		//throw exception
	}
	return p_node;
}

template <class T>
Node<T>* SplayTree<T>::add(T val, Node<T>* root) {

	Node<T>* p_node  = new_node(val);

	if(root == NULL){
		root = p_node;
		p_node = NULL;
		return root;
	}
	root = splay(val, root);
	cout<<"root = splay(val, root); "<< root->value <<"\n";

	/*Splay Top-Down approach:
	El nuveo nodo se inserta como raiz y la raiz para a ser un subarbol*/
	if(val < root->value) {
		p_node->left = root->left;
		p_node->right = root;
		root->left = NULL;
		root = p_node;
	} else if(val > root->value) {
		p_node->right = root->right;
		p_node->left = root;
		root->right = NULL;
		root = p_node;
	} else {
		return root;
	}
	p_node = NULL;
	return root;
}

template <class T>
Node<T>* SplayTree<T>::remove(T val, Node<T>* root) {
	Node<T> *temp;

	if(root == NULL)
		return NULL;

	root = splay(val, root);

	if(val != root->value)
		return root;
	else{
		temp = root;
		root = splay(val, root->left);
		root->right = temp->right;
	}

	free(temp);
	return root;
}

template <class T>
Node<T>* SplayTree<T>::find(T val, Node<T>* root) {
	return splay(val, root);
}

template <class T>
void SplayTree<T>::inorder(Node<T>* root)
{
		if (root)
		{
				inorder(root->left);
				cout<< "key: " <<root->value;
				if(root->left)
						cout<< " | left child: "<< root->left->value;
				if(root->right)
						cout << " | right child: " << root->right->value;
				cout<< "\n";
				inorder(root->right);
		}
}

template <class T>
void SplayTree<T>::preorder(Node<T>* root)
{
		if (root)
		{
				cout<< "key: " <<root->value;
				if(root->left)
						cout<< " | left child: "<< root->left->value;
				if(root->right)
						cout << " | right child: " << root->right->value;
				cout<< "\n";
				preorder(root->left);
				preorder(root->right);
		}
}


#endif /* Splay_H_ */
