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

long sum_seq(int n) {
	long acum = 0;
	for (int i = 1; i <= n; i++){
		acum += i;
	}
	//std::cout << acum << std::endl;
	return acum;
}

long sum_rec(int n) {
	if(n==1){
		return 1;
	} else{
		return n + sum_rec(n-1);
	}
}

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

long fact_rec(int n) {
	if(n == 1){
		return 1;
	} else{
		return n * fact_rec(n-1);
	}
	return 0;
}

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

long fib_rec(int n) {
	if(n==1||n==2){
		return 1;
	} else{
		return (fib_rec(n-1) + fib_rec(n-2));
	}
	return 0;
}

long gcd_seq(long a, long b) {
	return 0;
}

long gcd_rec(long a, long b) {
	return 0;
}

bool find_seq(int arr[], int size, int val) {
	return false;
}

bool find_rec(int arr[], int low, int high, int val) {
	return false;
}

int max_seq(int arr[], int size) {
	return 0;
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
