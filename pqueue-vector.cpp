/*************************************************************
 * File: pqueue-vector.cpp
 *
 * Implementation file for the VectorPriorityQueue
 * class.
 */
 
#include "pqueue-vector.h"
#include <Vector>
#include <string>
#include "error.h"

VectorPriorityQueue::VectorPriorityQueue() {
	// TODO: Fill this in!
	std::vector<std::string> vectorPriorityQueue;
}

VectorPriorityQueue::~VectorPriorityQueue() {
	// TODO: Fill this in!
}
// returns size
int VectorPriorityQueue::size() {
	// TODO: Fill this in!
	//priorityQueue.size();
	return vectorPriorityQueue.size();
}
// returns isempty or not queue
bool VectorPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	return vectorPriorityQueue.empty();
}
// adds new element
void VectorPriorityQueue::enqueue(string value) {
	vectorPriorityQueue.push_back(value);
	// TODO: Fill this in!
}
// peek smalests element
string VectorPriorityQueue::peek() {
	// TODO: Fill this in!
	if(vectorPriorityQueue.size()==0)  error("empty queue");
	string minvalue="";
	vector<string>::iterator mint;
    for (vector<string>::iterator t=vectorPriorityQueue.begin(); t!=vectorPriorityQueue.end(); ++t) {
		if(minvalue==""){

			mint=t;
			minvalue = *t;
		}else{
			string value1 = *t;
			if (value1<minvalue){
			mint=t;
			minvalue = *t;
			}
		}
	}
	return minvalue;
}
// peeks and deletes spalest element
string VectorPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if(vectorPriorityQueue.size()==0)  error("empty queue");
	string minvalue="";
	vector<string>::iterator mint;
    for (vector<string>::iterator t=vectorPriorityQueue.begin(); t!=vectorPriorityQueue.end(); ++t) {
		if(minvalue==""){

			mint=t;
			minvalue = *t;
		}else{
			string value1 = *t;
			if (value1<minvalue){
			mint=t;
			minvalue = *t;
			}
		}
	}
	vectorPriorityQueue.erase(mint);
	return minvalue;
}
