/*
 * intro.h
 *
 *  Created on: 08/08/2015
 *      Author: pperezm
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

unsigned long fact(int n) {
	unsigned long acum;

	if (n <= 0) {
		return 0;
	}

	acum = 1;
	for (int i = 1; i <= n; i++) {
		acum *= i;
	}
	return acum;
}

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned long sum(int arr[], int size) {
	unsigned long acum = 0;
	for (int i = 0; i < size; i++) {
		acum += arr[i];
	}
	return acum;
}

void reverse(int arr[], int size) {
	int aux;
	int i = 0;
	int j = size - 1;

	while (i < j) {
		aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;
		i++;
		j--;
	}
}

#endif /* FUNCTIONS_H_ */
