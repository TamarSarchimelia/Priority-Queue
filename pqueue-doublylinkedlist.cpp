/*************************************************************
 * File: pqueue-doublylinkedlist.cpp
 *
 * Implementation file for the DoublyLinkedListPriorityQueue
 * class.
 */
 
#include "pqueue-doublylinkedlist.h"
#include "error.h"
#include <iostream>

DoublyLinkedListPriorityQueue::DoublyLinkedListPriorityQueue() {
	head = NULL;
	logLen = 0;
	// TODO: Fill this in!
}

DoublyLinkedListPriorityQueue::~DoublyLinkedListPriorityQueue() {
	// TODO: Fill this in!
	
	DoublyLinkedList* curr = head;
	while (curr!= NULL) {
		DoublyLinkedList* next = curr->next;
		logLen--;
		delete curr;
		curr = next;
		if(logLen==1) break;
	}
}

int DoublyLinkedListPriorityQueue::size() {
	// TODO: Fill this in!
	
	return logLen;
}

bool DoublyLinkedListPriorityQueue::isEmpty() {
	// TODO: Fill this in!
	
	return logLen==0;
}

void DoublyLinkedListPriorityQueue::enqueue(string value) {
	// TODO: Fill this in!
	DoublyLinkedList* cell = new DoublyLinkedList;
	cell->value = value;
	cell->value2=logLen;
	cell->previous = NULL;
	if (head == NULL) {
		cell->next = NULL; 
		cell->previous=NULL;
		logLen++;
		head=cell;
		return;
	} 
	cell->next=head;
	head->previous=cell;
	logLen++;
	head=cell;
}

string DoublyLinkedListPriorityQueue::peek() {
	// TODO: Fill this in!
	if(logLen==0){
		error("empty queue");
	}
	DoublyLinkedList* curr = head;
	DoublyLinkedList* answer = head;
	for(int i=0; i<size(); i++){
		if(answer->value > curr->value){
			answer = curr;
		}
		//if(i=size()-1) break;
		curr=curr->next;

	}
	return answer->value;
}

string DoublyLinkedListPriorityQueue::dequeueMin() {
	// TODO: Fill this in!
	if(logLen==0){
		error("empty queue");
	}
	DoublyLinkedList* curr = head;
	DoublyLinkedList* answer = head;
	for(int i=0; i<size(); i++){
		if(curr!=NULL){
		if(answer==NULL|| answer->value > curr->value){
			answer = curr;
		}
		curr=curr->next;
		}

	}
	logLen--;
	/*if(answer==head){
		head=head->next;
		head->previous=NULL;
	}else if(answer->next==NULL){
		answer->previous->next==NULL;
	}else{
		answer->next=answer->next->next;
		answer->previous=answer->previous->previous;
	}*/
	string value = answer->value;
	if(head==answer){
		head=head->next;
	}
	if (answer->next!=NULL)
		answer->next->previous=answer->previous;
	if (answer->previous!=NULL)
		answer->previous->next=answer->next;
	delete answer;
	if(head!=NULL){
	DoublyLinkedList* curr1 = head;

}

	return value;
}

