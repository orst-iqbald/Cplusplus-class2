/*
 ** Name: queue.cpp coupled w/ queue.h and main.cpp
 ** Author: Danish Iqbal
 ** Date: 11/30/14 
** Description: Creation of a queue without use of iterators or hte queue container. Lists o
ut addback, remove front and isEmpty functions
 ** Input: None - adding in 1, 2, 3, 4 as numbers ** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 ******************************************************************/

#include "queue.h"
#include <iostream>
using namespace std;

// Construcutor fo rqueue
DynIntQueue::DynIntQueue() {
    front = NULL;
    rear = NULL;
}


// adds value ot back of queue
void DynIntQueue::addBack(int num) {
    if(isEmpty()){
	front = new QueueNode(num);//generating new note
	rear = front;// reassigning taht node to the rear
    }
    else
    {
	rear->next = new QueueNode(num);// generating new node in back
	rear = rear->next;
    }
}
// removes value form fron of queue
void DynIntQueue::removeFront(int &num)
{
    QueueNode *temp;
    if(isEmpty())
    {
	cout << "Queue is empty\n";
    }
    else
    {
	num = front->value;// reassinging what front is 
	temp = front;
	front = front->next;
	delete temp;// deleting it
    }
}

bool DynIntQueue::isEmpty() const
{
    if(front == NULL)
	return true;
    else
	return false;
}

