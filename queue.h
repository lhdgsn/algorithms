// queue.h
// Simple implementation of a queue
// Liam Hodgson
// 12 July 2016

#ifndef _QUEUE_H_
#define _QUEUE_H_

class Queue {
private:
	int *data;
	int nvals;
	int qlen;
	int head;
	int tail;
	bool growable; // indicates whether queue should be expanded in case of overflow

public:
	// constructor for dynamically sized queue
	Queue();

	// constructor for fixed queue
	Queue(int len);

	// destructor
	~Queue();

	// add an element to the end of the queue
	void enqueue(int val);

	// remove the first element in the queue
	int dequeue();
};

#endif