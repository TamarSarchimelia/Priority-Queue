/*************************************************************
 * File: pqueue-heap.cpp
 *
 * Implementation file for the HeapPriorityQueue
 * class.
 */
 
#include "pqueue-heap.h"
#include "error.h"
#include <iostream>




HeapPriorityQueue::HeapPriorityQueue() {
	// TODO: Fill this in!
	element = new string[4];
	maxSize = 4;
	element[0]="";
	currentSize = 0;
}


HeapPriorityQueue::~HeapPriorityQueue() {
	// TODO: Fill this in!
	delete[] element;
}
// returns size
int HeapPriorityQueue::size() {
	// TODO: Fill this in!
	return currentSize;
}
// returns queue is empty or not
bool HeapPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	
	return currentSize==0;
}
// adds new element
void HeapPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	
	if(currentSize+1==maxSize){
		grow();
	}
	currentSize++;
	element[currentSize] = value;
	bubbleUp(value, currentSize);
	
	
}
// peeks smalest element
string HeapPriorityQueue::peek() {
	// TODO: Fill this in!
	if(currentSize==0) error("empty queue");
	return element[1];

}
// peeks and deletes smalest element
string HeapPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if(currentSize==0) error("empty queue");
	string minElement = element[1];
	element[1] = element[currentSize];
	element[currentSize]="";
	bubbleDown(1);
	currentSize--;
	
	return minElement;
}
// grows size of array
void HeapPriorityQueue::grow(){
	maxSize *= 2;
	string* newArray = new string[maxSize];
	for (int i = 0; i <= currentSize; i++) {
		newArray[i] = element[i];
	}
	delete[] element;
	element = newArray;
}
// bubbles up the value on the three
void	HeapPriorityQueue::bubbleUp(string value,int n){
	if(n<2) return;
	string mother = element[n/2];
	if(mother>value){
	element[n] = mother;
	element[n/2] = value;
	bubbleUp(value,n/2);
	bubbleDown(n);
	}
}
// bubbles down the value on the three

void HeapPriorityQueue::bubbleDown(int n){
	if(2*n>currentSize/2) return;
	if(element[n]>element[2*n]){
		string mother = element[n];
		element[n] = element[2*n];
		element[2*n]=mother;
		bubbleDown(2*n);
		bubbleDown(n);
	}else if(element[n]>element[2*n+1]){
		string mother = element[n];
		element[n] = element[2*n+1];
		element[2*n+1]=mother;
		bubbleDown(2*n+1);
		bubbleDown(n);
	}
}



