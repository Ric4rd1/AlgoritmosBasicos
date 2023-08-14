/*
 * main.cpp
 *
 *  Created on: 11/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "dlist.h"

class ListTest : public UnitTest {
public:
	void runTest() {
		DList<int> b1;
		UnitTest::total_test = 47;

		/* TEST 1 */
		std::cout << "Test 1";
		ASSERT_TRUE(0 == b1.length());
		std::cout << " PASSED.\nTest 2";
		
		/* TEST 2 */
		ASSERT_TRUE(!strcmp("[]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 3";
		
		/* TEST 3 */
		b1.addFirst(2);
		ASSERT_TRUE(1 == b1.length());
		std::cout << " PASSED.\nTest 4";
		
		/* TEST 4 */
		ASSERT_TRUE(!strcmp("[2]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 5";
		
		/* TEST 5 */
		b1.addFirst(1);
		ASSERT_TRUE(2 == b1.length());
		std::cout << " PASSED.\nTest 6";
		
		/* TEST 6 */
		ASSERT_TRUE(!strcmp("[1, 2]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 7";
		
		/* TEST 7 */
		b1.add(3);
		ASSERT_TRUE(3 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 8";
		
		/* TEST 8 */
		b1.add(4);
		ASSERT_TRUE(4 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 9";
		
		/* TEST 9 */
		DList<int> b2(b1);
		ASSERT_TRUE(4 == b2.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3, 4]", b2.toString().c_str()));
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		b2.clear();
		ASSERT_TRUE(0 == b2.length());
		ASSERT_TRUE(true == b2.empty());
		ASSERT_TRUE(!strcmp("[]", b2.toString().c_str()));
		std::cout << " PASSED.\nTest 11";
		
		/* TEST 11 */
		ASSERT_TRUE(1 == b1.getFirst());
		std::cout << " PASSED.\nTest 12";
		
		/* TEST 12 */
		try {
			b2.getFirst();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 13";
		}

		/* TEST 13 */
		ASSERT_TRUE(1 == b1.removeFirst());
		ASSERT_TRUE(3 == b1.length());
		ASSERT_TRUE(!strcmp("[2, 3, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 14";
		
		/* TEST 14 */
		try {
			b2.removeFirst();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 15";
		}
		
		/* TEST 15 */
		ASSERT_TRUE(2 == b1.get(0));
		std::cout << " PASSED.\nTest 16";
		
		/* TEST 16 */
		ASSERT_TRUE(3 == b1.get(1));
		std::cout << " PASSED.\nTest 17";
		
		/* TEST 17 */
		ASSERT_TRUE(4 == b1.get(2));
		std::cout << " PASSED.\nTest 18";
		
		/* TEST 18 */
		try {
			b1.get(-1);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 19";
		}
		
		/* TEST 19 */
		try {
			b1.get(3);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 20";
		}

		/* TEST 20 */
		ASSERT_TRUE(true == b1.contains(3));
		std::cout << " PASSED.\nTest 21";
		
		/* TEST 21 */
		ASSERT_TRUE(false == b1.contains(10));
		std::cout << " PASSED.\nTest 22";
		
		/* TEST 22 */
		ASSERT_TRUE(false == b1.empty());
		std::cout << " PASSED.\nTest 23";
		
		/* TEST 23 */
		ASSERT_TRUE(true == b2.empty());
		std::cout << " PASSED.\nTest 24";
		
		/* TEST 24 */
		b2 = b1;
		ASSERT_TRUE(3 == b2.length());
		ASSERT_TRUE(!strcmp("[2, 3, 4]", b2.toString().c_str()));
		std::cout << " PASSED.\nTest 25";
		
		/* TEST 25 */
		b1.set(0, 1);
		ASSERT_TRUE(!strcmp("[1, 3, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 26";
		
		/* TEST 26 */
		b1.set(1, 2);
		ASSERT_TRUE(!strcmp("[1, 2, 4]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 27";
		
		/* TEST 27 */
		try {
			b1.set(-1, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 28";
		}
		
		/* TEST 28 */
		try {
			b1.set(3, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 29";
		}

		/* TEST 29 */
		b1.addFirst(1);
		b1.add(1);
		b1.add(5);
		b1.add(1);
		ASSERT_TRUE(0 == b1.indexOf(1));
		std::cout << " PASSED.\nTest 30";
		
		/* TEST 30 */
		ASSERT_TRUE(6 == b1.lastIndexOf(1));
		std::cout << " PASSED.\nTest 31";
		
		/* TEST 31 */
		ASSERT_TRUE(1 == b1.remove(4));
		ASSERT_TRUE(6 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 1, 2, 4, 5, 1]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 32";
		
		/* TEST 32 */
		ASSERT_TRUE(true == b1.removeFirstOcurrence(1));
		ASSERT_TRUE(5 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5, 1]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 33";
		
		/* TEST 33 */
		ASSERT_TRUE(false == b1.removeFirstOcurrence(100));
		std::cout << " PASSED.\nTest 34";
		
		/* TEST 34 */
		ASSERT_TRUE(true == b1.removeLastOcurrence(1));
		ASSERT_TRUE(4 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 35";
		
		/* TEST 35 */
		ASSERT_TRUE(false == b1.removeLastOcurrence(100));
		std::cout << " PASSED.\nTest 36";
		
		/* TEST 36 */
		DListIterator<int> itr1(&b1);
		itr1.begin();
		ASSERT_TRUE(1 == itr1());
		std::cout << " PASSED.\nTest 37";
		
		/* TEST 37 */
		++itr1;
		ASSERT_TRUE(2 == itr1());
		std::cout << " PASSED.\nTest 38";
		
		/* TEST 38 */
		b1.addAfter(itr1,10);
		ASSERT_TRUE(!strcmp("[1, 2, 10, 4, 5]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 39";
		
		/* TEST 39 */
		b2.clear();
		DListIterator<int> itr2(&b2);
		itr2.begin();
		try {
			b1.addAfter(itr2, 100);
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 40";
		}

		/* TEST 41 */
		b1.addBefore(itr1,10);
		ASSERT_TRUE(!strcmp("[1, 10, 2, 10, 4, 5]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 42";
		
		/* TEST 42 */
		try {
			b1.addBefore(itr2, 100);
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 43";
		}

		/* TEST 43 */
		ASSERT_TRUE(2 == b1.removeCurrent(itr1));
		ASSERT_TRUE(!strcmp("[1, 10, 10, 4, 5]", b1.toString().c_str()));
		std::cout << " PASSED.\nTest 44";

		/* TEST 44 */
		try {
			b1.removeCurrent(itr2);
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 45";
		}

		/* TEST 45 */
		++itr1;
		itr1 = itr1() * 3;
		ASSERT_TRUE(30 == itr1());
		std::cout << " PASSED.\nTest 46";
		
		/* TEST 46 */
		++itr1;
		ASSERT_TRUE(false == itr1.end());
		std::cout << " PASSED.\nTest 47";
		
		/* TEST 47 */
		ASSERT_TRUE(true == itr2.end());
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	ListTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


