/*********************************************************************
 *  * ** Program Filename: combat.h, includes main.cpp and makefile
 *   * ** Author: Danish Iqbal
 *    * ** Date: 11/19/14
 *     * ** Description: Assinment 3 header file for combat game. 
 *      * ** Input: Takes 2 characters from derived classes
 *       * ** Output: Combat of characters and output of final strength points
  *********************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Character// abstract class from which all other classes will be derived from
{
protected:
   string type;// name (ie goblin, blue, reptile, etc)
   int strength;
   int armor;
   int attack;
   int defense;
   bool achilles;// every monster has an achilles flag that is turned on only if they fight w/ a goblin that rolls a 12
   int team;
public:
   string getType() {return type;}
   int getAttack() {return attack;}
   int getDefense() {return defense;}
   int getArmor() {return armor;}
   int getStrength() {return strength;}
   int getTeam() {return team;}
   void setTeam(int t) {team  = t;}
   bool getAchilles() {return achilles;}
   void setAchilles(bool a) {achilles = a;}
   void setType(string t) {type = t;}
   void setStrength(int s)
        {
         strength = s;
//	if(strength<0)
//		strength == 0;
        }
   virtual void setAttack() //virtual function for derived classes
        {attack = (rand()%6 +1 + rand()%6+1);// rand fuction for 6 sided dice roll
        if(getAchilles() == true)// if achilles is true then attack is halved
                attack = attack/2;
        }
   virtual void setDefense()
        {defense = rand()%6 +1;
        }
   void setArmor(int a) {armor =a;}
};

class Goblin:public Character// all constructors have attack and defense values of 0 and respective values for armor and strenght from table 
{
public:
   Goblin() {type = "Goblin"; attack=0; defense=0; armor=3; strength =8; achilles = false; team =0;}
};

class Barbarian:public Character
{
public:
   Barbarian() { type = "Barbarian"; attack =0; defense =0; armor=0; strength =12; achilles =false;}
   virtual void setDefense()
        {defense = ((rand()%6 +1) + (rand()%6 +1));
        }
};

class Reptile:public Character
{
public:
   Reptile() {type = "Reptile"; attack =0; defense = 0; armor = 7; strength =8; achilles =false; team =0;}
};

class Blue:public Character
{
public:
   Blue() {type = "Blue"; attack =0; defense = 0; armor = 3; defense = 0; strength =12; achilles = false; team =0;}
   virtual void setAttack()
        {attack = ((rand()%10 +1) + (rand()%10 +1));
                if(getAchilles() == true)
                attack = attack/2;
        }
   virtual void setDefense()
        {defense = ((rand()%6 +1) + (rand()%6 +1));
        }
};

class Shadow:public Character
{
public:
   Shadow() {type = "Shadow"; attack =0; defense= 0; armor = 0; strength = 12; achilles = false; team =0;}
   virtual void setAttack()
        {attack = ((rand()%10 +1) + (rand()%10 +1));
                if(getAchilles() == true)
                attack = attack/2;
        }
};

