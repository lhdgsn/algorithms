// stack.cpp
// Implementation of a simple stack (inefficient method, to practice memory management)
// Liam Hodgson
// 9 July 2016

#include "stack.h"
#include <iostream>

using namespace std;

// default constructor
Stack::Stack() {
	data = 0; // set as null pointer
	nvals = 0;
}

// destructor
Stack::~Stack() {
	delete[] data;
}

// push
void Stack::push(int newval) {
	// allocate new array of correct size
	int *newdata = new int[++nvals];
	
	// copy old data to new array
	for(int i=0; i<nvals-1; i++)
		*(newdata+i) = *(data+i);

	// copy pushed value to end of new array
	newdata[nvals-1] = newval;
	
	delete[] data;
	data = newdata;
	newdata = 0;
}

// pop
int Stack::pop() {
	if(nvals==0) {
		cerr << "Can't pop, stack is empty." << endl;
		return 0;
	}
	return data[--nvals]; // don't actually need to resize array
}

// print
void Stack::print() {
	cout << "top | ";
	for(int i=nvals-1; i>=0; i--)
		cout << static_cast<int>(data[i]) << " ";
	cout << " | bottom" << endl;
}

// reset
void Stack::reset() {
	delete[] data;
	data = 0;
}

