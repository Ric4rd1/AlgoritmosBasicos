/*
 * main.cpp
 *
 *  Created on: 10/09/2015
 *      Author: pperezm
 */
#include <iostream>
#include "unit.h"
#include "busquedas.h"

class RecursionTest : public UnitTest {
public:
	void runTest() {
		int a2[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22};
		int size = 12;

		std::cout << "Test 1...";

		ASSERT_TRUE(bs_seq(a2, size, 20) == 10);
		std::cout << "PASSED.\nTest 2...";

		/* TEST 20 */
		ASSERT_TRUE(bs_seq(a2, size, 13) ==  7);
		std::cout << "PASSED.\nTest 3...";

		/* TEST 21 */
		ASSERT_TRUE(bs_rec(a2, size, 20) == 10);
		std::cout << "PASSED.\nTest 4...";

		/* TEST 22 */
		ASSERT_TRUE(bs_rec(a2, size, 13) ==  7);
		std::cout << "PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	RecursionTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
