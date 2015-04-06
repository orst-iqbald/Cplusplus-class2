#include <iostream>
#include <cstdlib>
#include <string>
#include "final.h"

using namespace std;

int main(){


	Room *box1;
	Room *box2;
	box1 = new RoomOne();
	box2 = new RoomTwo();
//	box1 = new RoomOne;
/*
	Room *box2;
	Room *box3;
        Room *box4;
        Room *box5;
        Room *box6;
        Room *box7;
        Room *box8;
        Room *box9;
        Room *box10;

	box1 = new RoomOne;
	box2 = new RoomTwo;
        box3 = new RoomThree;
        box4 = new RoomFour;
        box5 = new RoomFive;
        box6 = new RoomSix;
        box7 = new RoomSeven;
        box8 = new RoomEight;
        box9 = new RoomNine;
        box10 = new RoomTen;
*/

//	cout << box1->getNumber() <<endl;
//	cout << box1->getAnswer() <<endl;
//	cout << box1->getQuestion() << endl;
        cout <<"hi" << endl;
	cout << box1->getAnswer() << endl;


        Room *traverse;
        traverse = box1;

        cout << box1->getAnswer() << endl;
        cout << "traverse" << traverse->getAnswer() << endl;
	cout << box1->getStart() << endl;    
 //   box1->start->left = box2->start;
       // traverse = traverse->start->left;
        cout <<"box 2 traverse" << traverse->getAnswer() << endl;





//	cout << box1.getAnswer() << endl;

//	cout << box1->getAnswer() <<endl;
//	box1.left = box2.right;
//	box1->left->getNumber();


return 0;
}
