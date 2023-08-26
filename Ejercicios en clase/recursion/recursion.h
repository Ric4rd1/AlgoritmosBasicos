/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef RECURSION_H_
#define RECURSION_H_

#include "exception.h"
#include <iostream>

//O(n)
long sum_seq(int n) {
	long acum = 0;
	for (int i = 1; i <= n; i++){
		acum += i;
	}
	//std::cout << acum << std::endl;
	return acum;
}

//O(n)
long sum_rec(int n) {
	if(n==1){
		return 1;
	} else{
		return n + sum_rec(n-1);
	}
}

//O(n)
long fact_seq(int n) {
	if(n <= 0){
		return -1;
	}
	long acum = 1;
	for(int i = 1; i <= n; i++){
		acum *= i;
	}
	return acum;
}

//O(n)
long fact_rec(int n) {
	if(n == 1){
		return 1;
	} else{
		return n * fact_rec(n-1);
	}
	return 0;
}

//O(n)
long fib_seq(int n) {
	long acum = 1;
	long temp = 1;
	long aux;
	if (n == 1 || n == 2){
		return 1;
	}
	for(int i = 3; i <= n ; i++){
		aux = acum + temp;
		acum = temp;
		temp = aux;
	}
	return temp;
}

//O(2^n)
long fib_rec(int n) {
	if(n==1||n==2){
		return 1;
	} else{
		return (fib_rec(n-1) + fib_rec(n-2));
	}
	return 0;
}

//O(log n)
long gcd_seq(long a, long b) {
	//std::cout<<"como estas"<<std::endl;
	long aux;
	while(b != 0){
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

//O(log n)
long gcd_rec(long a, long b) {
	if(b == 0){
		//std::cout<<a<<std::endl;
		return a;
	} else{
		return gcd_rec(b, a%b);
	}
	//return 0;
}

//O(n)
//ciclo for con un if, el if es constante por lo tanto es O(n)
bool find_seq(int arr[], int size, int val) {
	for (int i = 1; i <= size; i++){
		 if (arr[i] == val){
			return true;
		 }
	}
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	int mid;
	bool aux;
	return false;
}

int max_seq(int arr[], int size) {
	int m = arr[0];
	// ciclo for O(n)
	for (int i = 1; i < size; i++) {
		if (m < arr[i]) {
			m = arr[i];
		}
	}
	return m;
}

int max_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_seq(int arr[], int size) {
	return 0;
}

int unimodal_rec(int arr[], int low, int high) {
	return 0;
}

int unimodal_rec(int arr[], int size) {
	return 0;
}

#endif /* RECURSION_H_ */
