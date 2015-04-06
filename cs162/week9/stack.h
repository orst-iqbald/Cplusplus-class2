/*
 *  ** Name: main.cpp coupled w/ stack.h and stack.cpp
 *   ** Author: Danish Iqbal
 *    ** Date: 11/30/14 
 *    ** Description: Creation of a stack without use of iterators or hte stack container. Lists o
 *    ut push, pop and peek functions
 *     ** Input: None - adding in 1, 2, 3, 4 as numbers 
 *     ** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 *      ******************************************************************/


#ifndef STACK_H_
#define STACK_H_
#include <iostream>
using namespace std;


class Stack {
protected:
    struct ListNode {
        int number;
        ListNode* next;
    }; 
    ListNode* head;
    int count; 
    
public:
    Stack();
    void push(int value);
    int pop();
    int peek();
    int size();
    void display();
};
#endif // STACK_H_
