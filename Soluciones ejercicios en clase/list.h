/*
 * linkedlist.h
 * solucion en clase
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class List<T>;
	friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
	List();
	List(const List<T>&) ;
	~List();

	void addFirst(T) ;
	void add(T) ;
	T    getFirst() const;
	T    removeFirst();
	int  length() const;
	T    get(int) const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	std::string toString() const;
	void operator= (const List&) ;

	void addBefore(ListIterator<T>&, T);
	void addAfter(ListIterator<T>&, T);
	T    removeCurrent(ListIterator<T>&);

	bool set(int, T);
	int  indexOf(T) const;
	int  lastIndexOf(T) const;
	T    remove(int);
	bool removeFirstOcurrence(T);
	bool removeLastOcurrence(T);

private:
	Link<T> *head;
	int 	size;

	friend class ListIterator<T>;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	Link<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
T List<T>::getFirst() const {
	if (empty()) {
		throw NoSuchElement();
	}
	return head->value;
}

template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val)  {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	if (empty()) {
		addFirst(val);
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
T List<T>::removeFirst() {
	T val;
	Link<T> *p;

	if (empty()) {
		throw NoSuchElement();
	}

	p = head;

	head = p->next;
	val = p->value;

	delete p;
	size--;

	return val;
}

template <class T>
T List<T>::get(int index) const {
	int pos;
	Link<T> *p;

	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		return getFirst();
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
void List<T>::clear() {
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
std::string List<T>::toString() const {
	std::stringstream aux;
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

template <class T>
List<T>::List(const List<T> &source)  {
	Link<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
	} else {
		p = source.head;
		head = new Link<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new Link<T>(p->value);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
void List<T>::operator=(const List<T> &source)  {
	Link<T> *p, *q;

	clear();
	if (source.empty()) {
		size = 0;
		head = 0;
	} else {
		p = source.head;
		head = new Link<T>(p->value);
		if (head == 0) {
			throw OutOfMemory();
		}
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new Link<T>(p->value);
			if (q->next == 0) {
				throw OutOfMemory();
			}
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
void List<T>::addBefore(ListIterator<T> &itr, T val) {
	Link<T> *newLink;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}

	// between
	if (itr.previous != 0) {
		newLink->next = itr.current;
		itr.previous->next = newLink;
		itr.previous = itr.previous->next;
		size++;
	// start
	} else {
		addFirst(val);
		itr.previous = head;
		itr.current = itr.previous->next;
	}
}

template <class T>
void List<T>::addAfter(ListIterator<T> &itr, T val) {
	Link<T> *newLink;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	newLink = new Link<T>(val);
	if (newLink == 0) {
		throw OutOfMemory();
	}


	// between
	if (itr.current != 0) {
		newLink->next = itr.current->next;
		itr.current->next = newLink;
		size++;
	// end
	} else if (itr.previous != 0) {
		itr.previous->next = newLink;
		itr.current = newLink;
		size++;
	// start
	} else {
		addFirst(val);
		itr.current = head;
		itr.previous = 0;
	}
}

template <class T>
T List<T>::removeCurrent(ListIterator<T> &itr) {
	T val;

	if (this != itr.theList) {
		throw IllegalAction();
	}

	if (itr.current == 0) {
		throw NoSuchElement();
	}

	if (itr.previous == 0) {
		head = itr.current->next;
	} else {
		itr.previous->next = itr.current->next;
	}

	val = itr.current->value;
	delete itr.current;
	itr.current = 0;

	//std::cout << "remove current = " << ((itr.current != 0)? itr.current->value : 0) << " previous: " << ((itr.previous != 0)? itr.previous->value : 0) << std::endl;
	return val;
}

template <class T>
bool List<T>::set(unsigned int index, T val) {

	/** tarea **/

	return true;
}

template <class T>
unsigned int List<T>::indexOf(T val) const {

	/** tarea **/

	return -1;
}

template <class T>
int List<T>::lastIndexOf(T val) const {

	/** tarea **/

	return -1;
}

template <class T>
T List<T>::remove(int index) {

	/** tarea **/

	return -1;
}

template <class T>
bool List<T>::removeFirstOcurrence(T val) {

	/** tarea **/

	return false;
}

template <class T>
bool List<T>::removeLastOcurrence(T val) {

	/** tarea **/

	return false;
}


template <class T>
class ListIterator {
public:
	ListIterator(List<T>*);
	ListIterator(const ListIterator<T>&);

	bool begin();
	bool end();
	T&   operator() ();
	bool operator++ ();
	void operator= (T);

private:
	Link<T> *current;
	Link<T> *previous;
	List<T> *theList;

	friend class List<T>;
};

template <class T>
ListIterator<T>::ListIterator(List<T> *aList) : theList(aList) {
	begin();
}

template <class T>
ListIterator<T>::ListIterator(const ListIterator<T> &source) : theList(source.theList) {
	begin();
}

template <class T>
bool ListIterator<T>::begin() {
	previous = 0;
	current = theList->head;
	return (current != 0);
}

template <class T>
T& ListIterator<T>::operator() () {
	if (current == 0) {
		throw NoSuchElement();
	}
	return current->value;
}

template <class T>
bool ListIterator<T>::end() {
	//std::cout << "1 end current = " << ((current != 0)? current->value : 0) << " previous: " << ((previous != 0)? previous->value : 0) << std::endl;
	if (current == 0) {
		if (previous != 0) {
			current = previous->next;
		}
	}
	return (current == 0);
}

template <class T>
bool ListIterator<T>::operator++ () {
	if (current == 0) {
		if (previous == 0) {
			current = theList->head;
		} else {
			current = previous->next;
		}
	} else {
		previous = current;
		current = current->next;
	}
	return (current != 0);
}

template <class T>
void ListIterator<T>::operator= (T val) {
	if (current == 0) {
		throw NoSuchElement();
	}
	current->value = val;
}

#endif /* LINKEDLIST_H_ */
