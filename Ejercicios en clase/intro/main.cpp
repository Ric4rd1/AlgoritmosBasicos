/*
 * main.cpp
 *
 *  Created on: 08/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include "unit.h"
#include "functions.h"

template <class T>
std::string arrayToString(T arr, int size) {
	std::stringstream aux;

	aux << "[" << arr[0];
	for (int i = 1; i < size; i++) {
		aux << ", " << arr[i];
	}
	aux << "]";
	return aux.str();
}

class FunctionText : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 10;
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		
		/* TEST 1 */
		std::cout << "Test 1";
		ASSERT_TRUE(0   == fact(-10));
		std::cout << " PASSED.\nTest 2";
		
		/* TEST 2 */
		ASSERT_TRUE(1   == fact(1));
		std::cout << " PASSED.\nTest 3";
		
		/* TEST 3 */
		ASSERT_TRUE(120 == fact(5));
		std::cout << " PASSED.\nTest 4";
		
		/* TEST 4 */
		ASSERT_TRUE(false == isPrime(-10));
		std::cout << " PASSED.\nTest 5";
		
		/* TEST 5 */
		ASSERT_TRUE(false == isPrime(1));
		std::cout << " PASSED.\nTest 6";
		
		/* TEST 6 */
		ASSERT_TRUE(true == isPrime(3));
		std::cout << " PASSED.\nTest 7";
		
		/* TEST 7 */
		ASSERT_TRUE(false == isPrime(1023));
		std::cout << " PASSED.\nTest 8";
		
		/* TEST 8 */
		ASSERT_TRUE(false == isPrime(1024));
		std::cout << " PASSED.\nTest 9";
		
		/* TEST 9 */
		ASSERT_TRUE(55 == sum(arr, 10));
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		reverse(arr, 10);
		ASSERT_TRUE(!strcmp("[10, 9, 8, 7, 6, 5, 4, 3, 2, 1]", arrayToString(arr,10).c_str()));
		std::cout << " PASSED.";
	}
};

int main(int argc, char* argv[]) {
	FunctionText test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


