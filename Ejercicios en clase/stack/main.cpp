#include <iostream>
#include <cstring>
#include "unit.h"
#include "stack.h"

class StackTest : public UnitTest {
public:
	void runTest() {
		StackVector<int> s1(5);
		UnitTest::total_test = 22;
		
		/* TEST 1 */
		std::cout << "Test 1...";
		ASSERT_TRUE(s1.empty());
		std::cout << " PASSED.\nTest 2...";
		
		/* TEST 2 */
		s1.push(4);
		ASSERT_TRUE(!strcmp("[4]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 3...";
		
		/* TEST 3 */
		s1.push(8);
		ASSERT_TRUE(!strcmp("[4, 8]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 4...";
		
		/* TEST 4 */
		s1.push(15);
		ASSERT_TRUE(!strcmp("[4, 8, 15]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 5...";
		
		/* TEST 5 */
		s1.push(16);
		ASSERT_TRUE(!strcmp("[4, 8, 15, 16]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 6...";
		
		/* TEST 6 */
		s1.push(23);
		ASSERT_TRUE(!strcmp("[4, 8, 15, 16, 23]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 7...";
		
		/* TEST 7 */
		try {
			s1.push(42);
			FAIL("Overflow not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("Overflow", e.what()));
			std::cout << " PASSED.\nTest 8...";
		}
		
		/* TEST 8 */
		ASSERT_TRUE(23 == s1.top());
		std::cout << " PASSED.\nTest 9...";
		
		/* TEST 9 */
		s1.pop();
		ASSERT_TRUE(16 == s1.top());
		std::cout << " PASSED.\nTest 10...";
		
		/* TEST 10 */
		s1.pop();
		ASSERT_TRUE(15 == s1.top());
		std::cout << " PASSED.\nTest 11...";
		
		/* TEST 11 */
		s1.pop();
		ASSERT_TRUE(8 == s1.top());
		std::cout << " PASSED.\nTest 12...";
		
		/* TEST 12 */
		s1.pop();
		ASSERT_TRUE(4 == s1.top());
		std::cout << " PASSED.\nTest 13...";
		
		/* TEST 13 */
		s1.pop();
		try {
			s1.top();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 14...";
		}

		/* TEST 14 */
		try {
			s1.pop();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 15...";
		}

		/* TEST 15 */
		s1.push(3);
		s1.push(2);
		s1.push(1);
		ASSERT_FALSE(s1.empty());
		std::cout << " PASSED.\nTest 16...";
		
		/* TEST 16 */
		s1.clear();
		ASSERT_TRUE(s1.empty());
		ASSERT_TRUE(!strcmp("[]", s1.toString().c_str()));
		std::cout << " PASSED.\nTest 17...";

		/* TEST 17 */
		StackList<int> s2;
		ASSERT_TRUE(s2.empty());
		std::cout << " PASSED.\nTest 18...";

		/* TEST 18 */
		s2.push(4);
		ASSERT_TRUE(!strcmp("[4]", s2.toString().c_str()));
		std::cout << " PASSED.\nTest 19...";
		
		/* TEST 19 */
		s2.push(8);
		ASSERT_TRUE(!strcmp("[8, 4]", s2.toString().c_str()));
		std::cout << " PASSED.\nTest 20...";
		
		/* TEST 20 */
		s2.push(15);
		ASSERT_TRUE(!strcmp("[15, 8, 4]", s2.toString().c_str()));
		std::cout << " PASSED.\nTest 21...";
		
		/* TEST 21 */
		s2.push(16);
		ASSERT_TRUE(!strcmp("[16, 15, 8, 4]", s2.toString().c_str()));
		std::cout << " PASSED.\nTest 22...";
		
		/* TEST 22 */
		s2.push(23);
		ASSERT_TRUE(!strcmp("[23, 16, 15, 8, 4]", s2.toString().c_str()));
		std::cout << " PASSED.\nTest 23...";

		/* TEST 23 */
		ASSERT_TRUE(23 == s2.top());
		std::cout << " PASSED.\nTest 24...";
		
		/* TEST 24 */
		s2.pop();
		ASSERT_TRUE(16 == s2.top());
		std::cout << " PASSED.\nTest 25...";
		
		/* TEST 25 */
		s2.pop();
		ASSERT_TRUE(15 == s2.top());
		std::cout << " PASSED.\nTest 26...";
		
		/* TEST 26 */
		s2.pop();
		ASSERT_TRUE(8 == s2.top());
		std::cout << " PASSED.\nTest 27...";
		
		/* TEST 27 */
		s2.pop();
		ASSERT_TRUE(4 == s2.top());
		std::cout << " PASSED.\nTest 28...";
		
		/* TEST 28 */
		s2.pop();
		try {
			s2.top();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 29...";
		}

		/* TEST 29 */
		try {
			s2.pop();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 30...";
		}

		/* TEST 30 */
		s2.push(3);
		s2.push(2);
		s2.push(1);
		ASSERT_FALSE(s2.empty());
		std::cout << " PASSED.\nTest 31...";
		
		/* TEST 31 */
		s2.clear();
		ASSERT_TRUE(s2.empty());
		std::cout << " PASSED.\nTest 32...";
		
		/* TEST 32 */
		ASSERT_TRUE(!strcmp("[]", s2.toString().c_str()));
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	StackTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
