/*
 ** Name: main.cpp coupled w/ queue.h and queue.cpp
 ** Author: Danish Iqbal
 ** Date: 11/30/14
 ** Description: Creation of a queue without use of iterators or hte queue container. Lists out addback, remove front and isEmpty functions
 ** Input: None - adding in 1, 2, 3, 4 as numbers
 ** Output: Places in 1, 2, 3, 4 as numbers and then removes those number. Displays those numbers placed in by programs as output.
 ******************************************************************/

#include <iostream>
#include "queue.h"
using namespace std;

int main(){

    DynIntQueue list;

    int entry;
    int number_entry;
    int i=0;

    cout << "How many numbers do you want to enter?\n";
    cin >> entry;
	
    cout << "Enter in the " << entry << "numbers followed by pressing enter. No error chcking so only enter in integers\n";
    while(i<entry){
	cin >> number_entry;
	list.addBack(number_entry);
	i++;
	}

    cout << "The queue has the following numbers in it,which are now being removed\n";
while(!list.isEmpty()){
    int num;
    list.removeFront(num);
    cout << num << " ";
}
cout << endl;
 
return 0;
}
