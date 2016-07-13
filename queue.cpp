// queue.cpp
// Simple implementation of a queue
// Liam Hodgson
// 12 July 2016

#include "queue.h"
#include <iostream>

using namespace std;

// constructor for dynamically sized queue
Queue::Queue() {
	data = 0;
	nvals = 0;
	qlen = -1;
	growable = TRUE;
	head = 0;
	tail = 0;
}

// constructor for fixed queue
Queue::Queue(int len) {
	data = new int[len];
	nvals = len;
	qlen = len;
	growable = FALSE;
	head = 0;
	tail = 0;
}

// destructor
Queue::~Queue() {
	delete[] data;
	data = 0;
}

// add an element to the end of the queue
void Queue::enqueue(int val) {
	// check if queue is empty
	if(nvals==0) {
		if(!growable){
			data[tail] = val;
			head = tail; // ensure head and tail point to same element
			qlen++;
			nval++;

			return;	
		}
		else{
			data = new int[1];
			data[0] = val;
			qlen++;
			nval++;

			return;
		}
		
	}

	// check if queue is full
	if(nvals==qlen) {
		if(!growable){
			cerr << "Queue is full" << endl;
			return;
		}
		else{
			int *data_tmp = new int[qlen+1];
			for(int i = 0; i < qlen; i++) // copy data to expanded queue
				data_tmp[i] = data[(head+i)%qlen];
			head = 0;
			tail = qlen-1;
			qlen++;
			delete[] data;
			data = data_tmp;
			data_tmp = 0;
		}
	}

	tail = (tail+1)%qlen; // queue grows to the right
	data[tail] = val;
	nval++;

	return;
}

// remove the first element in the queue
int Queue::dequeue() {
	// check if queue is empty
	if(nvals==0) {
		cerr << "Queue is empty" << endl;

		return 0;
	}

	nvals--;
	int tmp = data[head];
	head = (head+1)%qlen;
	return tmp;
}