/*************************************************************
 * File: pqueue-linkedlist.cpp
 *
 * Implementation file for the LinkedListPriorityQueue
 * class.
 */
#include <Vector>
#include <iostream>

#include "pqueue-linkedlist.h"
#include "error.h"

LinkedListPriorityQueue::LinkedListPriorityQueue() {
	// TODO: Fill this in!
}

LinkedListPriorityQueue::~LinkedListPriorityQueue() {
	// TODO: Fill this in!
}
// returns queues size
int LinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	return 	linkedListPriorityQueue.size();

}
// returns queue is empty or not

bool LinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!

	return linkedListPriorityQueue.empty();
}
// adds new element 
void LinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	if(linkedListPriorityQueue.size()==0){
		linkedListPriorityQueue.push_back(value);
		return;
	}
	for (vector<string>::iterator t=linkedListPriorityQueue.begin(); t!=linkedListPriorityQueue.end(); ++t) {
		if(value<*t){
			linkedListPriorityQueue.insert(t,value);
				return;
		}
	}
	linkedListPriorityQueue.push_back(value);


}
// peeks smalest element
string LinkedListPriorityQueue::peek() {
	// TODO: Fill this in!

	if(linkedListPriorityQueue.size()==0) error("empty queue");
	return linkedListPriorityQueue.at(0);
}
// peeks and deletes smalest element
string LinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!

	if(linkedListPriorityQueue.size()==0) error("empty queue");
	string value = linkedListPriorityQueue.at(0);
	vector<string>::iterator t=linkedListPriorityQueue.begin();
	linkedListPriorityQueue.erase(t);
	return value;
}

