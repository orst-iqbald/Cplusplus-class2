/*   Program Filename: combat.h, includes main.cpp and makefile
 *   * ** Author: Danish Iqbal
 *    * ** Date: 11/19/14
 *     * ** Description: Assinment 3 header file for combat game. 
 *      * ** Input: Takes 2 characters from derived classes
 *       * ** Output: Combat of characters and output of final strength points
  *********************************************************************/
#ifndef FINAL_H
#define FINAL_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Room// abstract class from which all other classes will be derived from
{
public:
   class InnerRoom
   {

	friend class Room;
	friend class RoomOne;
       friend class RoomTwo;
       friend class RoomThree;
       friend class RoomFour;
       friend class RoomFive;
       friend class RoomSix;
       friend class RoomSeven;
       friend class RoomEight;
       friend class RoomNine;
       friend class RoomTen;

  	int number;
	InnerRoom *north;
     	InnerRoom *south;
      	InnerRoom *left;
      	InnerRoom *right;
	InnerRoom (int number1, InnerRoom *north1 = NULL, InnerRoom *south1 = NULL, InnerRoom *left1 = NULL, InnerRoom *right1 = NULL)
	   {
	   number = number1;
	   north = north1;
 	   south = south1;
	   left = left1;
	   right = right;
	   }
	};
	InnerRoom *start;
	string question;
	int answer;
//public:
	Room() {start = new InnerRoom(0, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}// try just start();}
	int getAnswer() {return answer;}
	virtual void setAnswer(InnerRoom *ptr)
		{
		int a;
		a = ptr->number;
		answer = a*a;
		}
	string getQuestion() {return question;}
	virtual void setQuestion(string q) {question = "find the square of the box you're in";}
	int getStart() {return start->left;}
	
};

class RoomOne:public Room
{
public:
        RoomOne() {start = new InnerRoom(2, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}
};

class RoomTwo:public Room
{
public:
        RoomTwo() {start = new InnerRoom(2, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}
 		virtual void setQuestion(string q){
		question = "what's the square for this number";
		 if(getAnswer() == 4) 
			question = "This box to the fourth power is equal to what box squared";
		}
//	virtual void setAnswer()
};
class RoomThree:public Room
{
public:
        RoomThree() {start = new InnerRoom(3, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

        virtual void setQuestion(string q){
  //              question = "what's the square for this number";
    //             if(getAnswer() == number*number) 
                         question = "This box to the fourth power is equal to what box squared";
                }
};
class RoomFour:public Room
{
public:
        RoomFour() {start = new InnerRoom(4, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

        virtual void setQuestion(string q){
      //          question = "what's the square for this number";
        //         if(getAnswer() == number*number)
                          question = "This box to the third power is equal to what box squared";
                }

};
class RoomFive:public Room
{
public:
        RoomFive() {start = new InnerRoom(5, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

};
class RoomSix:public Room
{
public:
        RoomSix() {start = new InnerRoom(6, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

        virtual void setQuestion(string q){
          //      question = "what's the square for this number";
            //     if(getAnswer() == number*number)
                          question = "This box squared plus another box squared ower is equal to what box squared. All is in range of 1-10 inclusive";
                }

};
class RoomSeven:public Room
{
public:
        RoomSeven() {start = new InnerRoom(7, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

};
class RoomEight:public Room
{
public:
        RoomEight() {start = new InnerRoom(8, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

};
class RoomNine:public Room
{
public:
        RoomNine() {start = new InnerRoom(9, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

};
class RoomTen:public Room
{
public:
        RoomTen() {start = new InnerRoom(10, NULL, NULL, NULL,NULL), setQuestion(question), setAnswer(start);}

};


#endif
