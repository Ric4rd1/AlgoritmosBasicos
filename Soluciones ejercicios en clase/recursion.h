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

// funcion O(n)
long sum_seq(int n) {
	long acum = 0;
	// ciclo O(n)  lineal
	for (int i = 1; i <= n; i++) {
		acum += i;
	}
	return acum;
}

// funcion O(n)
long sum_rec(int n) {
	// funcion manda a llamar  n + sum_rec(n - 1)
	//															n +	sum_rec(n - 1)
	//																		n + sum_rec(n - 1)
	//																					... n = 0
	//																		return
	//															return
	//													return
	// este recorrido se manda a llamar como máximo n veces ya que n porque
	// teriman cuando n sea igual a 0, por lo tanto es O(n).

	// Sin embargo en la implementación este tipo de recursion, ocupa más tiempo
	// y memoria ya que en cada llamada recursiva requiere tiempo y memoria extra
	// para crear el sigiuiente nivel de recursion y para regresar el resultado
	// de la operación de cada nivel.

	if (n <= 1) {
		return 1;
	} else {
		return n + sum_rec(n - 1);
	}
}

// funcion O(n)
long fact_seq(int n) {
	long acum = 1;

	if (n <= 0) {
		return -1;
	}

	// ciclo O(n)  lineal
	for (int i = 1; i <= n; i++) {
		acum *= i;
	}
	return acum;
}

// funcion O(n)
long fact_rec(int n) {
	// funcion manda a llamar  n * fact_rec(n - 1)
	//															n *	fact_rec(n - 1)
	//																		n * fact_rec(n - 1)
	//																					... n = 0
	//																		return
	//															return
	//													return
	// este recorrido se manda a llamar como máximo n veces ya que n porque
	// teriman cuando n sea igual a 0, por lo tanto es O(n).

	// Sin embargo en la implementación este tipo de recursion, ocupa más tiempo
	// y memoria ya que en cada llamada recursiva requiere tiempo y memoria extra
	// para crear el sigiuiente nivel de recursion y para regresar el resultado
	// de la operación de cada nivel.
	if (n <= 0) {
		return -1;
	} else if (n == 1) {
		return 1;
	} else {
		return (n * fact_rec(n-1));
	}
}

// funcion O(n)
long fib_seq(int n) {
	long a, b, aux;
	int i;

	if (n == 1 || n == 2) {
		return 1;
	}

	a = 1;
	b = 1;
	i = 3;
	// ciclo O(n) porque su inremento va de 1 en 1
	while (i <= n) {
		aux = a + b;
		a = b;
		b = aux;
		i++;
	}
	return b;
}

// funcion O(2^n)
long fib_rec(int n) {
	// funcion manda a llamar fib_rec(n - 2) + fib_rec(n - 1) doble llamada recursiva:
	//															fib_rec(n - 2) +
	//																 					fib_rec(n - 2) +
	//															 									fib_rec(n - 2) + fib_rec(n - 1)
	//																								... n = 1 /0 /2
	//																								return
	//																					return
	//															 						fib_rec(n - 1)
	//																					fib_rec(n - 2) + fib_rec(n - 1)
	//																								... n = 1 /0 /2
	//																								return
	//															 						return
	//															fib_rec(n - 1) +
	//																 					fib_rec(n - 2) +
	//															 									fib_rec(n - 2) + fib_rec(n - 1)
	//																								... n = 1 /0 /2
	//																								return
	//																					return
	//															 						fib_rec(n - 1)
	//																					fib_rec(n - 2) + fib_rec(n - 1)
	//																								... n = 1 /0 /2
	//																								return
	//															 						return
	//															return
	// Este recorrido va generando un arbol, ya que genera una nueva rama por
	// cada llamada recursiva, por lo que su tiempo es mayor que el lineal,
	// podemos argumenta que dado que crece como una árbol su orden de magnitud
	// debe ser similar a la población de un árbol, esto es exponencial base 2
	// esto es O(2^n).

	// Sin embargo en la implementación este tipo de recursion, ocupa más tiempo
	// y memoria ya que en cada llamada recursiva requiere tiempo y memoria extra
	// para crear el sigiuiente nivel de recursion y para regresar el resultado
	// de la operación de cada nivel.
	if (n == 1 || n == 2) {
		return 1;
	} else {
		return (fib_rec(n - 1) + fib_rec(n - 2));
	}
}

//funcion log(n)
long gcd_seq(long a, long b) {
	long aux;
	// el ciclo se ejecuta menos de n o (b) veces, y en los primeros pasos descarta
	// o recorre gran parte de los elemnos, por lo que el ciclo es de tipo log(n)
	while (b != 0) {
		aux = b;
		b = a % b;
		a = aux;
	}
	return a;
}

//funcion log(n)
long gcd_rec(long a, long b) {
	// funcion manda a llamar  gcd_rec(b, a % b)
	//															gcd_rec(b, a % b)
	//																		gcd_rec(b, a % b)
	//																					... b == 0
	//																						return a
	// este recorrido se manda a llamar como máximo menos de n veces y
	// en proporción hacer menos pasos entre más grande sea el conjunto, por lo que
	// su tiempo es log(n)

	// Este tipo de recursion no hace llamadas recursivas de regreso, se conoce como
	// recursión iterativa porque tarda casi lo mismo que un ciclo for(iterativo),
	// es decir no ocupa más tiempo ni memoria.
	if (b == 0) {
		return a;
	} else {
		return gcd_rec(b, a % b);
	}
}

//funcion O(n)
bool find_seq(int arr[], int size, int val) {
	// ciclo for O(n)
	for (int i = 0; i < size; i++) {
		if (val == arr[i]) {
			return true;
		}
	}
	return false;
}

// funcion O log(n)
// correcto O(n), ya que se toam el peor caso que puede ser el ultimo elemento
bool find_rec(int arr[], int low, int high, int val) {
	int mid;
	bool aux;

  // cada llamada recursiva parte por la mitad el arreglo, por lo que todos
	// los recorridos que se generen serán menores n, es decir, cada siguiente paso
	// toma solo la mitad de lo que queda en el arreglo.

	if ( ((high - low) + 1) == 1) {
		return (val == arr[low]);
	} else {
		aux = false;
		mid = (high + low) / 2;
		aux = find_rec(arr, low, mid, val);
		if (!aux) {
			aux = find_rec(arr, mid + 1, high, val);
		}
		return aux;
	}
}

//funcion O(n)
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


// funcion O log(n)
// correcto O(n), ya que se toam el peor caso que puede ser el ultimo elemento
int max_rec(int arr[], int low, int high) {
	int mid, left, right;

	  // cada llamada recursiva parte por la mitad el arreglo, por lo que todos
		// los recorridos que se generen serán menores n, es decir, cada siguiente paso
		// toma solo la mitad de lo que queda en el arreglo.

	if ( ((high - low) + 1) == 1) {
		return arr[low];
	} else {
		mid = (high + low) / 2;
		left = max_rec(arr, low, mid);
		right = max_rec(arr, mid + 1, high);
		return ( (left > right)? left : right );
	}
}

int unimodal_seq(int arr[], int size) {
	if (size < 3) {
		return -1;
	}

	int mid;
	int low = 0;
	int high = size - 1;
	while (low < high) {
		mid = (high + low) / 2;
		if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
			return mid;
		} else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
			low = mid + 1;
		} else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
			high = mid - 1;
		}
	}
	return low;
}

int unimodal_rec(int arr[], int low, int high) {
	int mid;

	if (low <= high) {
		mid = (high + low) / 2;
		if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
			return mid;
		} else if (arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1]) {
			return unimodal_rec(arr, mid + 1, high);
		} else if (arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1]) {
			return unimodal_rec(arr, low, mid - 1);
		}
	}
	return -1;
}

int unimodal_rec(int arr[], int size) {

	if (size < 3) {
		return -1;
	}
	return unimodal_rec(arr, 0, size - 1);
}


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

//O(log n)
int bs_rec(int arr[], int size, int val) {
	return bs_aux(arr, 0, size - 1, val);
}
#endif /* RECURSION_H_ */
