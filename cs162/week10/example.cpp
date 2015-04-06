#include <iostream>
using namespace std;

class Room
{
public:
   class InnerRoom
   {
	friend class Room;
	friend class RoomOne;
	int value;
	InnerRoom *next;
	InnerRoom(int value1, InnerRoom *next1 = NULL)
	{
	value  = value1;
	next  = next1;
	}
    };
    InnerRoom *top;
    int number;

   Room() {top = new InnerRoom(1, NULL), setNumber(top);}
   int getNumber() {return number;}
   void setNumber(InnerRoom *ptr)
	{
	number = ptr->value;
	}	
};

class RoomOne:public Room
{
public:
	RoomOne() {top = new InnerRoom(2,NULL), setNumber(top);}
};

int main(){

	Room box1;
	cout << "hi" << endl;
	cout << box1.getNumber() << endl;
return 0;
}

