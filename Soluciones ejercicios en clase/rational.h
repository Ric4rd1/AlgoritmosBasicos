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

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num) : numerator(num), denominator(1) {}

Rational::Rational(int num, int dem) : numerator(num), denominator(dem) {
	normalize();
}

int Rational::getNumerator() const {
	return numerator;
}

int Rational::getDenominator() const {
	return denominator;
}

std::string Rational::toString() const {
	std::stringstream aux;

	aux << numerator << "/" << denominator;
	return aux.str();
}

void Rational::operator= (const Rational &right) {
	numerator   = right.numerator;
	denominator = right.denominator;
}

void Rational::operator+= (const Rational &right) {
	numerator    = (numerator * right.denominator) + (denominator * right.numerator);
	denominator *= right.denominator;
	normalize();
}

Rational::operator double () const {
	return numerator / (double) denominator;
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

	int d = gcd(numerator, denominator);

	numerator   = sign * (numerator / d);
	denominator = denominator / d;
}

Rational operator+ (const Rational &left, const Rational &right) {
	int num, dem;

	num = (left.getNumerator() * right.getDenominator()) + (left.getDenominator() * right.getNumerator());
	dem = left.getDenominator() * right.getDenominator();

	return Rational(num, dem);
}

Rational operator- (const Rational &left, const Rational &right) {
	int num, dem;

	num = (left.getNumerator() * right.getDenominator()) - (left.getDenominator() * right.getNumerator());
	dem = left.getDenominator() * right.getDenominator();

	return Rational(num, dem);
}

Rational operator- (const Rational &right) {
	return Rational(-right.getNumerator(), right.getDenominator());
}

bool operator== (const Rational &left, const Rational &right) {
	return (left.getNumerator() * right.getDenominator()) == (left.getDenominator() * right.getNumerator());
}

bool operator<  (const Rational &left, const Rational &right) {
	return (left.getNumerator() * right.getDenominator()) < (left.getDenominator() * right.getNumerator());
}

#endif /* RATIONAL_H_ */