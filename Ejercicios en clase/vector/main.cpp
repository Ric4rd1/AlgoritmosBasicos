/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "vector.h"

class VectorTest : public UnitTest {
public:
	void runTest() {
		int val = 1;
		UnitTest::total_test = 12;
		
		/* TEST 1 */
		std::cout << "Test 1...";
		try {
			Vector<int>(0);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 2...";
		}
		
		/* TEST 2 */
		try {
			Vector<int>(0, val);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 3...";
		}

		Vector<int> v1(5, val);
		Vector<int> v2(v1);
		/* TEST 3 */
		ASSERT_TRUE(!strcmp("[1, 1, 1, 1, 1]", v2.toString().c_str()));
		std::cout << " PASSED\n Test 4...";
		/* TEST 4 */
		ASSERT_TRUE(5 == v2.length());
		std::cout << " PASSED\n Test 5...";
		
		/* TEST 5 */
		try {
			v1.resize(0);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 6...";
		}

		/* TEST 6 */
		try {
			v1.resize(0, val);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 7...";
		}

		/* TEST 7 */
		v2.resize(2);
		ASSERT_TRUE(!strcmp("[1, 1]", v2.toString().c_str()));
		std::cout << " PASSED\n Test 8...";

		/* TEST 8 */
		val = 2;
		v2.resize(10, val);
		ASSERT_TRUE(!strcmp("[1, 1, 2, 2, 2, 2, 2, 2, 2, 2]", v2.toString().c_str()));
		std::cout << " PASSED\n Test 9...";

		/* TEST 9 */
		try {
			val = v2[100];
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED\n Test 10...";
		}

		/* TEST 10 */
		ASSERT_TRUE(v2[0] == 1);
		std::cout << " PASSED\n Test 11...";
		/* TEST 11 */
		ASSERT_TRUE(v2[2] == 2);
		std::cout << " PASSED\n Test 12...";

		/* TEST 12 */
		v1 = v2;
		ASSERT_TRUE(!strcmp("[1, 1, 2, 2, 2, 2, 2, 2, 2, 2]", v1.toString().c_str()));
		std::cout << " PASSED\n";
	}
};

int main(int argc, char* argv[]) {
	VectorTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}
