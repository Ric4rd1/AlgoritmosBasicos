/*
 * hash.h
 *
 *  Created on: 20/10/2015
 *      Author: clase
 */

#ifndef HASH_H_
#define HASH_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class Key, class Value>
class HashTable {
private:
	unsigned int (*func) (const Key);
	unsigned int size;
	unsigned int count;

	Key *keys;
	Key initialValue;
	Value *values;

	long indexOf(const Key) const;

public:
	HashTable(unsigned int, Key, unsigned int (*f) (const Key)) ;
	~HashTable();
	bool full() const;
	bool put(Key, Value);
	bool contains(const Key) const;
	Value get(const Key) ;
	void clear();
	std::string toString() const;
};

template <class Key, class Value>
HashTable<Key, Value>::HashTable(unsigned int sze, Key init, unsigned int (*f) (const Key))  {

}

template <class Key, class Value>
HashTable<Key, Value>::~HashTable() {

}

template <class Key, class Value>
bool HashTable<Key, Value>::full() const {
	return false;
}

template <class Key, class Value>
long HashTable<Key, Value>::indexOf(const Key k) const {
	return -1;
}

template <class Key, class Value>
bool HashTable<Key, Value>::put(Key k, Value v) {
	return false;
}

template <class Key, class Value>
bool HashTable<Key, Value>::contains(const Key k) const {
	return false;
}

template <class Key, class Value>
Value HashTable<Key, Value>::get(const Key k)  {
	Value v;

	return v;
}

template <class Key, class Value>
void HashTable<Key, Value>::clear() {

}

template <class Key, class Value>
std::string HashTable<Key, Value>::toString() const {
	std::stringstream aux;

	for (unsigned int i = 0; i < size; i++) {
		aux << "[ " << i << ", " << keys[i] << ", " << values[i] << "]\n";
	}
	return aux.str();
}
#endif /* HASH_H_ */
