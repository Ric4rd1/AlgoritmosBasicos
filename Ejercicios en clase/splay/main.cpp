/*
 * main.cpp
 *
 *  Created on: 29/10/2015
 *      Author: pperezm
 */

#include <iostream>
#include <cstring>
#include "unit.h"
#include "splay.h"

using namespace std;

class SplayTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 13;

		/* TEST 1 */
		SplayTree<int> splay;
		Node<int>* root = NULL;
		std::cout << "splay.add(1,root);" << "\n";
		root = splay.add(1,root);
		splay.inorder(root);

		root = splay.add(10,root);
		splay.inorder(root);
		root = splay.add(12,root);
		splay.inorder(root);
		root = splay.add(15,root);
		splay.inorder(root);
		root = splay.add(20,root);
		splay.inorder(root);
		root = splay.add(21,root);
		splay.inorder(root);
		root = splay.add(2,root);
		splay.inorder(root);
		root = splay.add(3,root);
		splay.inorder(root);
		root = splay.add(7,root);
		splay.inorder(root);
		std::cout << "splay.find(20,root);" << "\n";
		root = splay.find(20,root);
		splay.inorder(root);
		std::cout << "splay.find(20,root);" << "\n";
		root = splay.find(7,root);
		splay.inorder(root);

		std::cout << "splay.remove(20,root);" << "\n";
		root = splay.remove(20,root);
		splay.inorder(root);
		splay.preorder(root);

		}
};

int main(int argc, char* argv[]) {
	SplayTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}
