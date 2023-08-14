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
}

int Rational::getNumerator() const {
	return 0;
}

int Rational::getDenominator() const {
	return 0;
}

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

void Rational::operator= (const Rational &right) {
}

void Rational::operator+= (const Rational &right) {
}

Rational::operator double () const {
	return 0.0;
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
}

Rational operator+ (const Rational &left, const Rational &right) {
	return Rational();
}

Rational operator- (const Rational &left, const Rational &right) {
	return Rational();
}

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
