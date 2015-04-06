/*
 ** Name: queue.h coupled w/ main.cpp and queue.cpp
 ** Author: Danish Iqbal
 ** Date: 11/30/14 
 ** Description: Creation of a queue without use of iterators or hte queue container. Lists o
ut addback, remove front and isEmpty functions
 ** Input: None - adding in 1, 2, 3, 4 as numbers ** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 ******************************************************************/




#ifndef DYNINTQUEUE_H
#define DYNINTQUEUE_H
#include <iostream>
using namespace std;


class DynIntQueue 
{
protected:
    class QueueNode
    {
	friend class DynIntQueue;
	int value;
	QueueNode *next;
	QueueNode(int value1, QueueNode *next1 = NULL)
	   {
		value = value1;
		next =next1;
	   }
	};
    QueueNode *front;
    QueueNode *rear;
public:
    DynIntQueue();
    void addBack(int);
   // void getFront();
    void removeFront(int &);
    bool isEmpty() const;
};
#endif 
