/*
 * main.cpp
 *
 *  Created on: 29/10/2015
 *      Author: pperezm
 */

#include <iostream>
#include <cstring>
#include <string>
#include "unit.h"
#include "exception.h"
#include "heap.h"

using namespace std;

class HeapTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 10;
		
		/* TEST 1 */
		cout << "Test 1...\n";
		Heap<int> heap(5);
		ASSERT_TRUE(!strcmp("[]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 2...";
		
		/* TEST 2 */
		heap.add(10);
		ASSERT_TRUE(!strcmp("[10]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 3...";
		
		/* TEST 3 */
		heap.add(1);
		ASSERT_TRUE(!strcmp("[1 10]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 4...";
		
		/* TEST 4 */
		heap.add(100);
		heap.add(5);
		heap.add(3);
		ASSERT_TRUE(!strcmp("[1 3 100 10 5]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 5...";
		
		/* TEST 5 */
		try {
			heap.add(25);
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("Overflow", e.what()));
			std::cout << " PASSED.\nTest 6...";
		}
		
		/* TEST 6 */
		ASSERT_TRUE(1 == heap.remove());
		ASSERT_TRUE(!strcmp("[3 5 100 10]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 7...";
		
		/* TEST 7 */
		ASSERT_TRUE(3 == heap.remove());
		ASSERT_TRUE(!strcmp("[5 10 100]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 8...";
		
		/* TEST 8 */
		ASSERT_TRUE(5 == heap.remove());
		ASSERT_TRUE(!strcmp("[10 100]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 9...";
		
		/* TEST 9 */
		heap.clear();
		ASSERT_TRUE(!strcmp("[]", heap.toString().c_str()));
		std::cout << " PASSED.\nTest 10...";
		
		/* TEST 10 */
		try {
			heap.remove();
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\n";
		}
	}
};

int main(int argc, char* argv[]) {
	HeapTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}


