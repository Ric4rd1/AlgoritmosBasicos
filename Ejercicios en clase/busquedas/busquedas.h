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
/*
	int i = 0;
	while(i <= size && arr[i] < val){
		if(arr[i] == val){
			return i;
		} else{
			i++;
		}
	}
	return i;
	*/

int bs_seq(int arr[], int size, int val) {
	int low = 0;
	int high = size;
	int mid;

	while (low<high){
		mid = (high + low)/2;
		if (val == arr[mid]){
			return mid;
		}else if (val < arr[mid]){
			high = mid - 1;
		} else if(val> arr[mid]){
			low = mid + 1;
		}
	}
return low;
}

int bs_aux(int arr[], int low, int high, int val) {
	int mid;

	if (low <= high){
		mid  = (low + high) /2;
		if (val == arr[mid]){
		return mid;
		} else if (val < arr[mid]){
			high = mid - 1;
			return bs_aux(arr, low, high, val);
		} else if(val> arr[mid]){
			low = mid + 1;
			return bs_aux(arr, low, high, val);
		}
	}
	return low;
}

int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}
#endif
