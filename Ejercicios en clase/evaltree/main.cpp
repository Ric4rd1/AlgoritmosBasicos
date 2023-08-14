/*
 * main.cpp
 *
 *  Created on: 29/10/2015
 *      Author: pperezm
 */

#include <iostream>
#include <cstring>
#include "unit.h"
#include "evaltreeng.h"

using namespace std;

class EvalTreeTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 17;

		/* TEST 1 */
		cout << "Test 1\n";
		try {
			EvalTree a("1 2 + x 3 *");
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 2";
		}

		EvalTree a("x x * 2 x * - 1 +");
		EvalTree b;

		/* TEST 2 */
		ASSERT_TRUE(!strcmp("1 + x * 2 - x * x ", a.inorder().c_str()));
		std::cout << " PASSED.\nTest 3";

		/* TEST 3 */
		ASSERT_TRUE(!strcmp("+ 1 - * x 2 * x x ", a.preorder().c_str()));
		std::cout << " PASSED.\nTest 4";

		/* TEST 4 */
		ASSERT_TRUE(!strcmp("1 x 2 * x x * - + ", a.postorder().c_str()));
		std::cout << " PASSED.\nTest 5";

		/* TEST 5 */
		ASSERT_TRUE(!strcmp("+ 1 - * * x 2 x x ", a.levelOrder().c_str()));
		std::cout << " PASSED.\nTest 6";

		/* TEST 6 */
		ASSERT_TRUE(b.empty() == true);
		std::cout << " PASSED.\nTest 7";

		/* TEST 7 */
		ASSERT_TRUE(a.empty() == false);
		std::cout << " PASSED.\nTest 8";

		/* TEST 8 */
		ASSERT_TRUE(b.height() == 0);
		std::cout << " PASSED.\nTest 9";

		/* TEST 9 */
		ASSERT_TRUE(a.height() == 4);
		std::cout << " PASSED.\nTest 10";

		/* TEST 10 */
		ASSERT_TRUE(b.howManyLeaves() == 0);
		std::cout << " PASSED.\nTest 11";

		/* TEST 11 */
		ASSERT_TRUE(a.howManyLeaves() == 5);
		std::cout << " PASSED.\nTest 12";

		/* TEST 12 */
		try {
			b.minValue();
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 13";
		}

		/* TEST 13 */
		ASSERT_TRUE(a.minValue() == '1');
		std::cout << " PASSED.\nTest 14";

		/* TEST 14 */
		ASSERT_TRUE(a.find('1') == true);
		std::cout << " PASSED.\nTest 15";

		/* TEST 15 */
		ASSERT_TRUE(a.find('9') == false);
		std::cout << " PASSED.\nTest 16";

		/* TEST 16 */
		ASSERT_TRUE(a.eval(3) == -2);
		std::cout << " PASSED.\nTest 17";

		/* TEST 17 */
		EvalTree *aux = a.derive();
		ASSERT_TRUE(!strcmp("0 + x * 0 + 2 * 1 - x * 1 + x * 1 ", aux->inorder().c_str()));
		delete aux;
		aux = 0;
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	EvalTreeTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


