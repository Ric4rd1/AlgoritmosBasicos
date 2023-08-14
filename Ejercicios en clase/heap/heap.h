/*
 * heap.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>

template <class T>
class Heap {
private:
	T *data;
	unsigned int size;
	unsigned int count;

	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;
	void heapify(unsigned int);
	void swap(unsigned int, unsigned int);

public:
	Heap(unsigned int) ;
	~Heap();
	bool empty() const;
	bool full() const;
	void add(T) ;
	T remove() ;
	void clear();
	std::string toString() const;
};

template <class T>
Heap<T>::Heap(unsigned int sze)  {
}

template <class T>
Heap<T>::~Heap() {
}

template <class T>
bool Heap<T>::empty() const {
}

template <class T>
bool Heap<T>::full() const {
	return false;
}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return 0;
}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return 0;
}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return 0;
}

template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
	T aux = data[i];
	data[i] = data[j];
	data[j] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {
}

template <class T>
void Heap<T>::add(T val)  {
}

template <class T>
T Heap<T>::remove()  {
	T aux;

	return aux;
}

template <class T>
void Heap<T>::clear() {
}


template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;

	aux << "[";
	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		}
		aux << data[i];
	}
	aux << "]";
	return aux.str();
}
#endif /* HASH_H_ */
