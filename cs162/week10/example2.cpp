#include <iostream>
using namespace std;

struct InnerRoom
{
        int value;
   	InnerRoom *next; 
	InnerRoom(int value1, InnerRoom *next1 = NULL)
	{
		value = value1;
		next = next1;
	}
};
class Room
{
public:
        InnerRoom *north;
	InnerRoom *south;
	InnerRoom *left;
	InnerRoom *right;

        Room() {north = new InnerRoom(0, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(0,NULL), right = new InnerRoom(0,NULL),  setValueS(north, south);} 
        int getValueN() {return north->value;}
        virtual void setValueS(InnerRoom *north, InnerRoom *south)
                {
                int a = north->value;
		south->value = a*a;
                }
};

class RoomOne:public Room
{
public:
        RoomOne() {north = new InnerRoom(1, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(0,NULL), right = new InnerRoom(0,NULL), setValueS(north, south); }
};

class RoomTwo:public Room
{
public:
        RoomTwo() {north = new InnerRoom(2, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(1,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right);}
	virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)
		{
                int a = north->value;
                south->value = a*a;
		right->value = 16;
		}
};

class RoomThree:public Room
{
public:
        RoomThree() {north = new InnerRoom(3, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(2,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right); }
        virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)       
	        {
                int a = north->value;
                south->value = a*a;
                right->value = 81;
                }
};

class RoomFour:public Room
{
public:
        RoomFour() {north = new InnerRoom(4, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(3,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right);}
        virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)         
		{
                int a = north->value;
                south->value = a*a;
                right->value = 64;
                }

};

class RoomFive:public Room
{
public:
        RoomFive() {north = new InnerRoom(5, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(4,NULL), right = new InnerRoom(0,NULL), setValueS(north, south); }
};
class RoomSix:public Room
{
public:
        RoomSix() {north = new InnerRoom(6, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(5,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right);}
        virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)
                {
                int a = north->value;
                south->value = a*a;
                right->value = 8;
                }
};
class RoomSeven:public Room
{
public:
        RoomSeven() {north = new InnerRoom(7, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(6,NULL), right = new InnerRoom(0,NULL), setValueS(north, south); }
};
class RoomEight:public Room{
public:
        RoomEight() {north = new InnerRoom(8, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(7,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right);}
        virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)
                {
                int a = north->value;
                south->value = a*a;
                right->value = 64;
                }
};
class RoomNine:public Room
{
public:
        RoomNine() {north = new InnerRoom(9, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(8,NULL), right = new InnerRoom(0,NULL), setValueS(north, south, right); }
        virtual void setValueS(InnerRoom *north, InnerRoom *south, InnerRoom *right)
                {
                int a = north->value;
                south->value = a*a;
                right->value = 81;
                }
};

class RoomTen:public Room{
public:
        RoomTen() {north = new InnerRoom(10, NULL), south = new InnerRoom(0, NULL), left = new InnerRoom(9,NULL), right = new InnerRoom(0,NULL), setValueS(north, south);}
};


int main(){

        cout << "hi" << endl;

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

        box1 = new RoomOne();
        box2 = new RoomTwo();
        box3 = new RoomThree();
        box4 = new RoomFour();
        box5 = new RoomFive();
        box6 = new RoomSix();
        box7 = new RoomSeven();
        box8 = new RoomEight();
        box9 = new RoomNine();
        box10 = new RoomTen();

	box1->north = box2->left;
	box2->north = box3->left;

        Room *ptr;
        ptr = box1;
	ptr = ptr->north;

        InnerRoom *traverse;
        traverse = box1->north;
        cout << "traverse" << traverse->value << endl;
	traverse = traverse->next;
        cout << "traverse" << traverse->value << endl;

	traverse = traverse->next;
       // traverse = traverse->left;



return 0;
}
