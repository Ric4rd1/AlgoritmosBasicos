/*
 * main.cpp
 *
 *  Created on: 11/10/2021
 *      Author: bvaldesa
 */

#include <iostream>
#include <cstring>
#include "unit.h"
#include "avl.h"

using namespace std;

class AVLTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 13;

		AVL<int> avl;
		std::cout << avl.preorder().c_str();
		avl.add(10);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		avl.add(20);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		avl.add(15);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 1 0) (10 0 0) (20 0 0)]"
		avl.add(17);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 2 -1) (10 0 0) (20 1 1) (17 0 0)]"
		avl.add(8);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 2 0) (10 1 1) (8 0 0) (20 1 1) (17 0 0)]"
		avl.add(9);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 2 0) (9 1 0) (8 0 0) (10 0 0) (20 1 1) (17 0 0)]"
		avl.add(4);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 3 1) (9 2 1) (8 1 1) (4 0 0) (10 0 0) (20 1 1) (17 0 0)]"
		avl.add(3);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 3 1) (9 2 1) (4 1 0) (3 0 0) (8 0 0) (10 0 0) (20 1 1) (17 0 0)]"
		avl.add(2);
		std::cout << avl.preorder().c_str()<< endl<< endl;
		//"[(15 3 1) (4 2 0) (3 1 1) (2 0 0) (9 1 0) (8 0 0) (10 0 0) (20 1 1) (17 0 0)]"
	}
};

int main(int argc, char* argv[]) {
	AVLTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}
