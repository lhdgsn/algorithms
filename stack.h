// stack.h
// Implementation of a simple stack (inefficient method, to practice memory management)
// Liam Hodgson
// 10 July 2016

#ifndef _STACK_H_
#define _STACK_H_

class Stack {
private:
	int *data; // data array
	int nvals; // number of values in stack

public:
	// default constructor
	Stack();		

	// destructor
	~Stack();

	// push
	void push(int newval);

	// pop
	int pop();

	// print
	void print();

	// reset
	void reset();

	// isempty
	bool isEmpty() { return nvals==0; }

	// length
	int length() { return nvals; }

};

#endif