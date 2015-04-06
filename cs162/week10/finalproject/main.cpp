/*********************************************************************
 * ** Program Filename: Final.h along w/ main.cpp
 * ** Author: Danish Iqbal
 * ** Date: 12/8/14
 * ** Description: A maze like progrma where the user has to solve a math problem to get form one room to the next
 * ** Input: answers to the mathematical question
 * ** Output: places you in next room.
 * *********************************************************************/


#include <iostream>
#include <cstdlib>
#include <string>
#include "final.h"

using namespace std;

/*********************************************************************
 * ** Function: Direction
 * ** Description: Takes a pointer and displays the properties of the room (ie question, #, answer)
 * ** Parameters: InnerRoom pointer
 * ** Pre-Conditions: Inner room pointer adn set up class objects
 * ** Post-Conditions: Will return a number that will be placed in while loop
 * *********************************************************************/

int direction(InnerRoom *traverse);

/*********************************************************************
 * ** Function: specialDirection
 * ** Description: Takes a pointer and displays the properties of the room (ie question, #, answer)
 * ** Parameters: InnerRoom pointer and the class should hae the special bool variable on
 * ** Pre-Conditions: Inner room pointer adn set up class objects
 * ** Post-Conditions: Will return a number that will be placed in while loop
 * *********************************************************************/

int specialdirection(InnerRoom *traverse);

int main(){

// Creating of room pointers which will later be assigned to subclasses 
        Room *box1;
        Room *box2;
        Room *box3;
        Room *box4;
        Room *box5;
        Room *box6;
        Room *box7;
        Room *box8;
        Room *box9;
        Room *box10;

// Assignment of room pointers to Room subclasses
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

// Assignment of pointers in each room to proper
        box1->start->left = box2->start;
        box1->start->north = box1->start;

        box2->start->left = box3->start;
        box2->start->south = box4->start;
        box2->start->north = box1->start;

        box3->start->left = box4->start;
        box3->start->south = box9->start;
        box3->start->north = box2->start;

        box4->start->left = box5->start;
        box4->start->south = box8->start;
        box4->start->north = box3->start;

        box5->start->left = box6->start;
        box5->start->north = box4->start;

        box6->start->left = box7->start;
        box6->start->south = box8->start;
        box6->start->north = box7->start;

        box7->start->left = box8->start;
        box7->start->north = box6->start;

        box8->start->left = box9->start;
        box8->start->north = box7->start;

        box9->start->left = box10->start;
        box9->start->north = box8->start;

// Creation of variables going which will equal the output of the direction function
        int going =0;
// Creation of pointer which will travel through the rooms
        InnerRoom *traverse;
        traverse = box1->start;
//while loop that decides what next direction will be based on functions outputs
        while(traverse->number != 10){
                if(traverse ->special == true){
                going = specialdirection(traverse);
                        if(going==0){
                        traverse = traverse->north;}
                        else if(going==1){
                        traverse = traverse->left;}
                        else if(going==2){
                        traverse = traverse->south;}
                }
                else{
                going = direction(traverse);
                        if(going==0){
                        traverse = traverse->north;}
                        else{
                        traverse = traverse->left;
                        }
                }
        }
	
	cout << "Congrats! You reached room 10 and you've completed the game!" << endl;

return 0;
}

int direction(InnerRoom *traverse)
{
        int go;// variable that will contain output
        int ans;
        int ans_actual = traverse->answer;// answer from pointer


        cout << traverse->question << " Room value: " << traverse->number << endl;
        cout << "Enter in answer\n";
        cin >> ans;

        if(ans == ans_actual){
        go = 1;}
        else{
        go = 0;}
        return go;
}

int specialdirection(InnerRoom *traverse)
{
        int go;// output value
        char challenging;// input of y or n if they want second part of quesiton
        int num;// equivalnt to room number
        int ans1;// first answr to easy question
        int ans2;// answer to harder question
        num = traverse->number;

        cout << "For an easier question, what's the square of the room's value " << traverse->number << " Enter in answer below\n";
        cin >> ans1;

        if(ans1 == num*num){
        cout << "Do you want a challenging question ? Enter in y or n\n";
        cin >> challenging;
        }

        if(ans1 == num*num && challenging == 'n'){
        cout << "You're gong to the next room\n";
        }
        else if(ans1 !=num*num)
        cout << "You're going back to the previous room";
        else {
        cout << traverse->question << " Room value: " << traverse->number << endl;
        cout << "Enter in answer\n";
        cin >> ans2;
        }

        if(ans2== traverse->answer && ans1==num*num && challenging == 'y')
                go = 2;
        else if(ans1== num*num && challenging == 'n')
                go = 1;
        else if(ans2 != traverse->answer)
                go =0;
        else
                go =0;
        return go;

}
           
