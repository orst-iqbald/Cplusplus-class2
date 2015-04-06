/*
 ** Name: main.cpp coupled w/ stack.h and stack.cpp
 ** Author: Danish Iqbal
 ** Date: 11/30/14 
** Description: Creation of a stack without use of iterators or hte stack container. Lists o
ut push, pop and peek functions
 ** Input: None - adding in 1, 2, 3, 4 as numbers 
** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 ******************************************************************/



#include <iostream>
#include "stack.h"

using namespace std;

int main(){

	Stack list;
   
     int entry;
    int number_entry;
    int i=0;

    cout << "How many numbers do you want to enter?\n";
    cin >> entry;

    cout << "Enter in the " << entry << "numbers followed by pressing enter. No error chcking so only enter in integers\n";

    while(i<entry){
        cin >> number_entry;
        list.push(number_entry);
        i++;
        }

	cout << "Now we'll display the values you puhsed into the stack\n";
	list.display();
	cout << "Now I'll pop the first value and then show you what the first value in the stack is using the peek function\n";
	list.pop();
        cout << "peek is " << list.peek() << endl;
	

return 0;
}
