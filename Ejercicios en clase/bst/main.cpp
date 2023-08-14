/*
 * main.cpp
 *
 *  Created on: 29/10/2015
 *      Author: pperezm
 */

#include <iostream>
#include <cstring>
#include "unit.h"
#include "bst.h"

using namespace std;

class BSTTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 13;
		
		/* TEST 1 */
		std::cout << "Test 1...";
		BST<int> bst;
		ASSERT_TRUE(!strcmp("[]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 2...";
		
		/* TEST 2 */
		bst.add(15);
		ASSERT_TRUE(!strcmp("[15]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 3...";
		
		/* TEST 3 */
		bst.add(10);
		ASSERT_TRUE(!strcmp("[10 15]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15 10]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 4...";
		
		/* TEST 4 */
		bst.add(20);
		ASSERT_TRUE(!strcmp("[10 15 20]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15 10 20]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 5...";
		
		/* TEST 5 */
		bst.add(11);
		bst.add(12);
		bst.add(14);
		bst.add(13);
		ASSERT_TRUE(!strcmp("[10 11 12 13 14 15 20]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15 10 11 12 14 13 20]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 6...";
		
		/* TEST 6 */
		bst.add(5);
		bst.add(2);
		bst.add(7);
		bst.add(1);
		bst.add(3);
		bst.add(6);
		bst.add(8);
		ASSERT_TRUE(!strcmp("[1 2 3 5 6 7 8 10 11 12 13 14 15 20]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15 10 5 2 1 3 7 6 8 11 12 14 13 20]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 7...";
		
		/* TEST 7 */
		bst.add(18);
		bst.add(25);
		ASSERT_TRUE(!strcmp("[1 2 3 5 6 7 8 10 11 12 13 14 15 18 20 25]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[15 10 5 2 1 3 7 6 8 11 12 14 13 20 18 25]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 8...";
		
		/* TEST 8 */
		ASSERT_TRUE(false == bst.find(100));
		std::cout << " PASSED.\nTest 9...";
		
		/* TEST 9 */
		ASSERT_TRUE(true == bst.find(13));
		ASSERT_TRUE(true == bst.find(18));
		ASSERT_TRUE(true == bst.find(3));
		std::cout << " PASSED.\nTest 10...";
		
		/* TEST 10 */
		bst.remove(15);
		ASSERT_TRUE(!strcmp("[1 2 3 5 6 7 8 10 11 12 13 14 18 20 25]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[14 10 5 2 1 3 7 6 8 11 12 13 20 18 25]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 11...";
		
		/* TEST 11 */
		bst.remove(5);
		ASSERT_TRUE(!strcmp("[1 2 3 6 7 8 10 11 12 13 14 18 20 25]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[14 10 3 2 1 7 6 8 11 12 13 20 18 25]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 12...";
		
		/* TEST 12 */
		bst.remove(25);
		ASSERT_TRUE(!strcmp("[1 2 3 6 7 8 10 11 12 13 14 18 20]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[14 10 3 2 1 7 6 8 11 12 13 20 18]", bst.preorder().c_str()));
		std::cout << " PASSED.\nTest 13...";
		
		/* TEST 13 */
		bst.removeAll();
		ASSERT_TRUE(!strcmp("[]", bst.inorder().c_str()));
		ASSERT_TRUE(!strcmp("[]", bst.preorder().c_str()));
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	BSTTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


