/*
 * recursion.h
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */

#ifndef BUSQUEDAS_H_
#define BUSQUEDAS_H_

#include "exception.h"
#include <iostream>


int bs_seq(int arr[], int size, int val) {
	int mid;
	int low = 0;
	int high = size - 1;

	while (low < high) {
		mid = (high + low) / 2;
		if (val == arr[mid]) {
			return mid;
		} else if (val < arr[mid]) {
			high = mid - 1;
		} else if (val > arr[mid]) {
			low = mid + 1;
		}
	}
	return low;
}

int bs_aux(int arr[], int low, int high, int val) {
	int mid;

	if (low <= high) {
		mid = (high + low) / 2;
		if (val == arr[mid]) {
			return mid;
		} else if (val < arr[mid]) {
			return bs_aux(arr, low, mid - 1, val);
		} else if (val > arr[mid]) {
			return bs_aux(arr, mid + 1, high, val);
		}
	}
	return low;
}

int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}

#endif
