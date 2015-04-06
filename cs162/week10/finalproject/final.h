/*  * Program Filename: final.h, includes main.cpp and makefile
 *  ** Author: Danish Iqbal
 *  ** Date: 12/9/14
 *  ** Description: maze for user to solve math puzzels. 
 *  ** Input: Takes user through rooms if they answer math question
 *  ** Output: going through rooms
 *          *********************************************************************/
#ifndef FINAL_H
#define FINAL_H

#include <iostream>
#include <string>
using namespace std;

struct InnerRoom
{
        string question;// question particular to the room
        int number;// room number
        int answer;// answer to the question for that room
        bool special;// denotes if a room has a tow part question
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
        InnerRoom *start;// includes start struct w/ all pointers
        Room() {start = new InnerRoom("q", 0, 0, false, NULL, NULL, NULL,NULL), setAnswer(start), setQuestion(start);}
        int getNumber() {return start->number;}
        virtual void setQuestion(InnerRoom *start)// sets question in struct
                {
                string q;
                q = "Find the square of the box room's value";
                start->question  = q;
                }
        virtual void setAnswer(InnerRoom *start)// sets answer for each
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

#endif
