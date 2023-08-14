#ifndef VECTOR_H_
#define VECTOR_H_
#include "exception.h"
#include <sstream>
template <class T>
class Vector {
private:
	unsigned int size;
	T	*data;

public:
	Vector(unsigned int) ;
	Vector(unsigned int, T&) ;
	Vector(const Vector<T>&) ;
	~Vector();

	unsigned int length() const;
	unsigned int resize(unsigned int) ;
	unsigned int resize(unsigned int, T&) ;
	std::string toString() const;

	T& operator[](unsigned int) const ;
	void operator=(const Vector<T>&);
};

template <class T> Vector<T>::Vector(unsigned int numberOfElements)  {
	if (numberOfElements == 0) {
		throw RangeError();
	}
	size = numberOfElements;
	data = new T[size];
	if (data == 0) {
		throw OutOfMemory();
	}
}
template <class T> Vector<T>::Vector(unsigned int numberOfElements, T &initialValue)  {
	if (numberOfElements == 0) {
		throw RangeError();
	}
	size = numberOfElements;
	data = new T[size];
	if (data == 0) {
		throw OutOfMemory();
	}

	for (unsigned int i = 0; i < size; i++) {
		data[i] = initialValue;
	}
}
template <class T> Vector<T>::Vector(const Vector<T> &source)  {
	size = source.size;
	data = new T[size];
	if (data == 0) {
		throw OutOfMemory();
	}

	for (unsigned int i = 0; i < size; i++) {
		data[i] = source.data[i];
	}
}
template <class T> Vector<T>::~Vector() {
	delete [] data;
	data = 0;
	size = 0;
}

template <class T> unsigned int Vector<T>::length() const {
	return size;
}

template <class T> unsigned int Vector<T>::resize(unsigned int newSize)  {
	if (newSize == 0) {
		throw RangeError();
	}
	T *newData = new int[newSize];
	if (newData == 0) {
		throw OutOfMemory();
	}

	if (newSize <= size) {
		for (unsigned int i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	} else {
		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
	}

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

template <class T>
unsigned int Vector<T>::resize(unsigned int newSize, T &initValue)  {
	if (newSize == 0) {
		throw RangeError();
	}
	T *newData = new int[newSize];
	if (newData == 0) {
		throw OutOfMemory();
	}

	if (newSize <= size) {
		for (unsigned int i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	} else {
		unsigned int i;
		for (i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		for (; i < newSize; i++) {
			newData[i] = initValue;
		}
	}

	delete [] data;
	data = newData;
	size = newSize;

	return size;
}

template <class T> std::string Vector<T>::toString() const {
	std::stringstream aux;

	aux << "[" << data[0];
	for (unsigned int i = 1; i < size; i++) {
		aux << ", " << data[i];
	}
	aux << "]";
	return aux.str();
}

template <class T>
T& Vector<T>::operator[] (unsigned int index) const  {
	if (index < 0 || index >= size) {
		throw IndexOutOfBounds();
	}
	return data[index];
}

template <class T>
void Vector<T>::operator=(const Vector<T> &right) {
	if (size != right.size) {
		resize(right.size);
	}
	for (unsigned int i = 0; i < right.size; i++) {
		data[i] = right.data[i];
	}
}
#endif /* VECTOR_H_ */
