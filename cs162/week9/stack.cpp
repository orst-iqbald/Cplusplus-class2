/*
 *  ** Name: main.cpp coupled w/ stack.h and main.cpp
 *   ** Author: Danish Iqbal
 *    ** Date: 11/30/14 
 *    ** Description: Creation of a stack without use of iterators or hte stack container. Lists o
 *    ut push, pop and peek functions
 *     ** Input: None - adding in 1, 2, 3, 4 as numbers 
 *     ** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 *      ******************************************************************/


#include "stack.h"
#include <iostream>
using namespace std;

// Constucutor for stack. Notice how head->next and number are NOT null.
Stack::Stack() {
    head = new ListNode();
     // setting values for constructor
    head->next = 0;
    head->number = 0;
}


// Pushes value onto the top of the stack.
void Stack::push(int value) {
    ListNode* top = new ListNode();
    top->number = value;

    // make a current listnode that you assign head to 
    ListNode* current = head;
    current = current->next;
    head->next = top;// can't do current->next = top since current isnt' initiatied in new command
    top->next = current;
}


// displays the whole stack and all values in it. this uses a pointer, but professor didn't say that this could be one of the functions
void Stack::display()
{
        ListNode *nodePtr = head;
        while(nodePtr)
        {
        cout<< nodePtr ->number << " ";
        nodePtr = nodePtr->next;
        }
}

// Pops the top-most value off the stack and returns its value.
int Stack::pop() {
    if (head->next == NULL) {
        cout << "No can do. Empty stack." << endl;
        return 0;
    } else {
        ListNode* remove = head->next;

        // reassign value of top before  deleting it
        int top = remove->number;
        head->next = head->next->next;
        delete remove;

        return top;
    }
}

// Gives you top value of stack
int Stack::peek() {
    if (head->next == NULL) {
        cout << "No can do. It's an empty stack." << endl;
        return 0;
    } else {
        return head->next->number;
    }
}

