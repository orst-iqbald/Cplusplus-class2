#include <iostream>
#include <string>
using namespace std;

struct InnerRoom
{	
	string question;
	int number;
	int answer;
	bool special;
        InnerRoom *north;
        InnerRoom *south;
        InnerRoom *left;
        InnerRoom *right;
        InnerRoom (string question1, int number1, int answer1, bool special1, InnerRoom *north1 = NULL, InnerRoom *south1 = NULL, InnerRoom *left1 = NULL, InnerRoom *right1 = NULL)
           {
	   question = question1;
           number = number1;
	   answer = answer1;
	   special = special1;
           north = north1;
           south = south1;
           left = left1;
           right = right;
           }
};

class Room
{
public:
        InnerRoom *start;
	Room() {start = new InnerRoom("q", 0, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
        int getNumber() {return start->number;}
	virtual void setQuestion(InnerRoom *start)
		{
		string q;
		q = "Find the square of the box room's value";
		start->question  = q;
		}
        virtual void setAnswer(InnerRoom *start)
                {
                int a = start->number;
                start->answer = a*a;
                }
};

class RoomOne:public Room
{
public:
        RoomOne() {start = new InnerRoom("q", 1, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};

class RoomTwo:public Room
{
public:
        RoomTwo() {start = new InnerRoom("q", 2, 0, true, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}

        virtual void setQuestion(InnerRoom *start)
                {
                string q;
                q = "This room's value to the 4th power is which number squared. If you answer right you can skip rooms, otherwise you'll go to the next room";
                start->question  = q;
                }
        virtual void setAnswer(InnerRoom *start)
                {
                int a = start->number;
                start->answer = a*a;
                }
};

class RoomThree:public Room
{
public:
        RoomThree() {start = new InnerRoom("q", 3, 0, true, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}

        virtual void setQuestion(InnerRoom *start)
                {
                string q;
                q = "This room's value to the 4th power is which number squared. If you answer right you can skip rooms, otherwise you'll go to the next room";
                start->question  = q;
                }
        virtual void setAnswer(InnerRoom *start)
                {
                int a = start->number;
                start->answer = a*a;
                }
};

class RoomFour:public Room
{
public:
        RoomFour() {start = new InnerRoom("q", 4, 0, true,  NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}

        virtual void setQuestion(InnerRoom *start)
                {
                string q;
                q = "This room's value to the 3rd power is which number squared. If you answer right you can skip rooms, otherwise you'll go to the next room";
                start->question  = q;
                }
        virtual void setAnswer(InnerRoom *start)
                {
                int a = start->number;
                start->answer = 2*a;
                }
};

class RoomFive:public Room
{
public:
        RoomFive() {start = new InnerRoom("q", 5, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};

class RoomSix:public Room
{
public:
        RoomSix() {start = new InnerRoom("q", 6, 0, true, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}

        virtual void setQuestion(InnerRoom *start)
                {
                string q;
                q = "This number squared and another number squared is equal to what number less than 11 that's squared";
                start->question  = q;
                }
        virtual void setAnswer(InnerRoom *start)
                {
                int a = start->number;
                start->answer = 8;
                }
};

class RoomSeven:public Room
{
public:
        RoomSeven() {start = new InnerRoom("q", 7, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};
class RoomEight:public Room
{
public:
        RoomEight() {start = new InnerRoom("q", 8, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};
class RoomNine:public Room
{
public:
        RoomNine() {start = new InnerRoom("q", 9, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};
class RoomTen:public Room
{
public:
        RoomTen() {start = new InnerRoom("q", 10, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
};

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
			

return 0;
}

int direction(InnerRoom *traverse)
{
	int go;// variable that will contain output
	int ans;
	int ans_actual = traverse->answer;
	
	
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
	int go;
	char challenging;
	int num;
	int ans1;
	int ans2;
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
