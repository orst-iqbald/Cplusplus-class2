/*  Program Filename: main.cpp coupled w/ combat.h and makefile. This program has not been run yet.
 ** Author: Danish Iqbal
 ** Date: 11/7/14
 ** Description: Contains fucntions where user picks two characters who then battle between themselves
 ** Input: User input for characters who will engage in battle
 ** Output: Output for winning character (judged by whoever has greater strength points).
 ******************************************************************/

#include <iostream>
#include "combat.h"

using namespace std;

/* Function: input()
 * Description: asks user input and generates objects of classes that are derived from the character class.
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: will give you two objects from derived classes of the Chracter class.
 */
void input(Character* &object1);//, Character* &object2);

/* Function: round(Character obj1, Character obj2)
 * Description: places the inputs (objects from the derived classes of Character) into combat. It also changes the objects armor and attack values (in the case of Shadow nad Achilles). Finally, it changes the strenght value of the defender)obj 2).
 * Parameters: Character object1 adn Character object 2
 * Pre-Conditions: instantiated character objects
 * Post-Conditions: will return the strenght value of object2. 
 */
int round(Character* &object1, Character* &object2);

int main(){
// Creation of dynamic character objects that will later be filled in as a Character subclass
        Character *object1;
        Character *object2;
// User chooses which monsters will be object 1 and object 2	
	cout << "Let's select the attacker\n";
	input(object1);
	cout << "Let's select the defender\n";
	input(object2);	
// do while loop for a round of fighting between the creatures. Loop ends when one createure gets has a strength below zero indicating that they're deal
	do{
	   round(object1, object2);
	   round(object2, object1);
	}while((object1->getStrength() >0 && object2->getStrength() >0) && (object1->getStrength() <50));

// Statement declaring the winner/ loser and their respective points. 
	if(object1->getStrength() > object2->getStrength())
		cout << object1 ->getType() 
		<< " is winner with " 
		<< object1 -> getStrength() 
		<< " strength points, while the defender " << object2 -> getType() 
		<< " has this many strenght points " << object2 -> getStrength() << endl; 
	else
		cout << object2 ->getType() 
		<< " is winner with " 
		<< object2 -> getStrength() 
		<< " strength point, while the defender " << object1 -> getType() 
		<< " has this many strenght points " << object1 -> getStrength() << endl;  

return 0;
}

void input(Character* &object1){// Character* &object2){

//enum Charac {Goblin =1, Barbarian, Reptile, Blue, Shadow};
int attacker_num;// used in switch statement for above enums
//int defender_num;// used in swtithc statement for above enums

	cout << "Which character do you want? Pick a number between 1 and 5 signifying the following: Goblin =1, Barbarian =2, Reptile =3, Blue =4, Shadow=5. \n";
	cin >> attacker_num;
        while(attacker_num<1 || attacker_num>5){
        	cout<< "You must enter in a number between 1 and 5. Enter again\n";
		cin >> attacker_num;
                }

	if( attacker_num ==1){
		cout << "You picked Goblin for attacker\n";
                object1 = new Goblin();}
	else if(attacker_num ==2){
		cout << "You picked Barbarian for attacker\n";
                object1 = new Barbarian();}
	else if(attacker_num==3){
		cout << "You picked Reptile for attacker\n";
                object1 = new Reptile();}
	else if(attacker_num==4){
		cout << "You picked Blue for attacker\n";
                object1 = new Blue();}
	else if(attacker_num==5){
		cout << "You picked Shadow for attacker\n";
                object1 = new Shadow();}
}

int round(Character* &object1, Character* &object2){// objects from the input function are passed to this function

int combat_attack;//attacker dice roll
int combat_defense;// defenders dice roll
int combat_damage;// attackers dice - defenders dice - defenders armor
int combat_strength;// original strength points - combat_damage

//**** generating combat attack adn defnese
	object1 -> setAttack();
	combat_attack = object1->getAttack();// 11/18 changed form set to get
	// combat defense value	
	object2 ->setDefense();
	combat_defense = object2->getDefense();// 11/18 change to get
	// setting achilles value for subsequent rounds
	if(object1->getType() == "Goblin" && object1->getAttack() == 12)
		object2->setAchilles(true);// When fignting w goblin attack ability for next round is halved

// settign shadow values and combat damage values
	if(object2->getType() == "Shadow")// Shadow - 50% chance that no damage
		combat_damage = (rand()%1)*(combat_attack - combat_defense);
	else
		combat_damage = (combat_attack - combat_defense) - object2->getArmor();

// final comat strength vlaue
	combat_strength  = (object2->getStrength() - combat_damage);
	object2->setStrength(combat_strength);// setting strenght as new strenght value

return combat_strength;
}	
