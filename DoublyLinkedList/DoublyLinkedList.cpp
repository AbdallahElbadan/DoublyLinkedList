/// Testing doubly linked list
#include <cassert>
#include <iostream>
#include <cstdlib>
#include "unorderedDoubleLinkedList.h"
using namespace std;
bool testInsertFirst() {
	cout << "Testing insertFirst" << endl;
	unorderedDoubleLinkedList<int> exampleList;
	exampleList.insertFirst(100);
	exampleList.insertFirst(90);
	assert(exampleList.length() == 2);
	assert(exampleList.search(100)); //check for specific node
	exampleList.insertLast(110);
	exampleList.insertLast(120);
	assert(exampleList.length() == 4);
	exampleList.print(true);
	cout << "Forward Print Expected Output: 90 100 110 120" << endl;
	exampleList.print(false);
	cout << "Reverse Print Expected Output: 120 110 100 90" << endl;
	exampleList.destroyList();
	return true;
}
bool testInsertLast() {
	cout << "Testing insertLast" << endl;
	unorderedDoubleLinkedList<double> exampleList;
	exampleList.insertLast(2.1);
	exampleList.insertLast(2.2);
	exampleList.insertFirst(2.0);
	assert(exampleList.length() == 3);
	exampleList.insertFirst(1.9);
	cout << "Forward Print Expected Output: 1.90 2.0 2.1 2.2" << endl;
	exampleList.print(true);
	cout << "Reverse Print Expected Output: 2.2 2.1 2.0 1.9" << endl;
	exampleList.print(false);
	exampleList.destroyList();
	return true;
}
bool testInsertNode() {
	cout << "Testing insertNode" << endl;
	unorderedDoubleLinkedList<int> exampleList;
	exampleList.insertNode(320, 0);
	assert(exampleList.length() == 1);
	exampleList.insertNode(310, 0);
	assert(exampleList.length() == 2);
	exampleList.insertNode(330, 2);
	exampleList.insertLast(340);
	exampleList.insertNode(315, 1);
	assert(exampleList.search(315)); //check for specific node
	exampleList.insertNode(335, 4);
	cout << "Forward Print Expected Output: 310 315 320 330 335 340" << endl;
	exampleList.print(true);
	cout << "Reverse Print Expected Output: 340 335 330 320 315 310" << endl;
	exampleList.print(false);
	exampleList.destroyList();
	return true;
}
bool testDeleteNode() {
	cout << "Testing deleteNode" << endl;
	unorderedDoubleLinkedList<int> exampleList;
	exampleList.insertFirst(310);
	exampleList.insertLast(315);
	exampleList.insertLast(320);
	exampleList.insertLast(330);
	exampleList.insertLast(335);
	exampleList.insertLast(340);
	cout << "Starting List: 310 315 320 330 335 340" << endl;
	exampleList.print(true);
	//test delete from middle
	exampleList.deleteNode(315);
	assert(!exampleList.search(315));
	assert(exampleList.length() == 5);
	exampleList.deleteNode(335);
	cout << "Forward Print Expected Output: 310 320 330 340" << endl;
	exampleList.print(true);
	cout << "Reverse Print Expected Output: 340 330 320 310" << endl;
	exampleList.print(false);
	// test Deleting first and last from list
	exampleList.deleteNode(340);
	assert(!exampleList.search(340));
	assert(exampleList.length() == 3);
	exampleList.deleteNode(310);
	assert(!exampleList.search(310));
	assert(exampleList.length() == 2);
	cout << "Forward Print Expected Output: 320 330" << endl;
	exampleList.print(true);
	cout << "Reverse Print Expected Output: 330 320" << endl;
	exampleList.print(false);
	exampleList.destroyList();
	return true;
}
bool testErrorMessages() {
	cout << "Testing Error Messages" << endl;
	unorderedDoubleLinkedList<int> exampleList;
	exampleList.insertFirst(310);
	exampleList.insertLast(315);
	exampleList.insertLast(320);
	exampleList.insertLast(330);
	exampleList.insertLast(335);
	exampleList.insertLast(340);
	cout << "Starting List: 310 315 320 330 335 340" << endl;
	exampleList.print(true);
	cout << "TEST --- Insert node test with index too big" << endl;
	exampleList.insertNode(370, 7);
	cout << "TEST --- Insert node test with index too small" << endl;
	exampleList.insertNode(300, -1);
	cout << "TEST --- Delete node that isn't in list" << endl;
	exampleList.deleteNode(500);
	exampleList.destroyList();
	cout << "TEST --- Delete node from empty list" << endl;
	exampleList.deleteNode(500);
	return true;
}
bool testTypeSupport() {
	cout << "Testing Template Type Support" << endl;
	unorderedDoubleLinkedList<string> stringList;
	stringList.insertFirst("one");
	stringList.insertLast("three");
	stringList.insertNode("two", 1);
	cout << "Forward Print Expected Output: one two three" << endl;
	stringList.print(true);
	cout << "Reverse Print Expected Output: three two one" << endl;
	stringList.print(false);
	stringList.destroyList();
	return true;
}
int main()
{
	unorderedDoubleLinkedList<int> exampleList;
	cout << "--- Beginning Tests of insert functions --- " << endl;
	if (testInsertFirst()) {
		cout << "insertFirst tests finished";
		cout << "\n\n";
	}
	if (testInsertLast()) {
		cout << "insertLast tests finished";
		cout << "\n\n";
	}
	if (testInsertNode()) {
		cout << "insertNode tests finished";
		cout << "\n\n";
	}
	if (testDeleteNode()) {
		cout << "deleteNode tests finished";
		cout << "\n\n";
	}
	///// Test delete node by index for pairs
	/*
	if(testDeleteNodeAtIndex()) {
	cout << "deleteNodeAtIndex tests finished";
	cout << "\n\n";
	}
	*/
	testErrorMessages();
	testTypeSupport();
	cout << "All tests executed\n";
	return 0;
}

