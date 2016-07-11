// stack_test.cpp
// Used to test stack.cpp implementation
// Liam Hodgson
// 10 July 2016

#include "stack.h"
#include <iostream>

using namespace std;

int main(){
	Stack test_stack;
	cout << "Stack created" << endl;
	cout << "Empty? " << test_stack.isEmpty() << endl;
	cout << "Length = " << test_stack.length() << endl;

	test_stack.push(5);
	cout << "Pushed to stack" << endl;
	cout << "Empty? " << test_stack.isEmpty() << endl;
	cout << "Length = " << test_stack.length() << endl;
}
