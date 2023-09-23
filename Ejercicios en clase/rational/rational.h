/*
 * rational.h
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */

#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "exception.h"
#include <string>
#include <sstream>

class Rational {
private:
	int numerator;
	int denominator;

	void normalize();

public:
	Rational();
	Rational(int);
	Rational(int, int);
	Rational(const Rational&);

	int getNumerator() const;
	int getDenominator() const;
	std::string toString() const;

	void operator=   (const Rational&);
	void operator+=  (const Rational&);

	operator double () const;
};

Rational::Rational() {
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int num){
    numerator = num;
    denominator = 1;
}

Rational::Rational(int num, int dem){
    if (dem == 0){
        numerator = 0;
        denominator = 1;
    }else{
        numerator = num;
        denominator = dem;
    }
	normalize();
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return numerator;
}

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

//operadores que me modifican a mi mismo 
//1 parametro
void Rational::operator= (const Rational &right) {
	numerator = right.numerator;
	denominator = right.numerator;
}

void Rational::operator+= (const Rational &right) {

}

Rational::operator double () const {
	return numerator/(double) denominator;
}

int gcd(int a, int b) {
	int aux;

	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

void Rational::normalize() {
	//Obtener el signo y dejar numerator y denominator positivo
	int sign = 1;
	if (numerator < 0) {
		sign = -1;
		numerator = -numerator;
	}
	if (denominator < 0) {
		sign = -sign;
		denominator = -denominator;
	}
	if (denominator == 0) {
		throw RangeError();
	}

	//simplificar
	//maximo común multiplo
	int d = gcd(numerator, denominator);

	numerator   = sign * (numerator / d);
	denominator = denominator / d;
}

//no me involucran a mi mismo, necesito 2 parametros, osea 2 objetos y devuelve un objeto nuevo
Rational operator+ (const Rational &left, const Rational &right) {
	return Rational();
}

Rational operator- (const Rational &left, const Rational &right) {
	return Rational();
}

//solo hace el objeto negativo
Rational operator- (const Rational &right) {
	return Rational();
}


bool operator== (const Rational &left, const Rational &right) {
	return false;
}

bool operator<  (const Rational &left, const Rational &right) {
	return false;
}

#endif /* RATIONAL_H_ */
