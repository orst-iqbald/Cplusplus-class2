/** Name: main.cpp coupled w/ combat.h and makefile.
 ** Author: Danish Iqbal
 ** Date: 11/7/14
 ** Description: Contains fucntions where user picks two lineup of monsters  who then battle between themselves. First, Second, and Third places are decided as well as the total strenght points of each team (player 1 and 2)
 ** Input: User input for characters who will engage in battle
 ** Output: Output for winning character as well as 1st, 2nd and 3rd place. (judged by whoever has greater strength points).
 ******************************************************************/

#include <iostream>
#include "tournament.h"
#include <queue>
#include <stack>

using namespace std;
         
/* Function: round(queue Character obj1, queue Character obj2)
 * Description: places the inputs (objects from the derived classes of Character) into combat. It also changes the objects armor and attack values (in the case of Shadow nad Achilles). Finally, it changes the strenght value of the defender)obj 2).
 * Parameters: Character object1 adn Character object 2
 * Pre-Conditions: instantiated character objects
 * Post-Conditions: will return the strenght value of object2. 
 */ 
int round(queue <Character*> &object1, queue <Character*> &object2);
/* Function: recover(queue Character &winner)
 * Description: when a character who has just won the round goes back into the line they regain a quarter or half of their strength through this function
 * Parameters: Character object1 
 * Pre-Conditions: instantiated character objects
 * Post-Conditions: will give the object hafl or a quarter of their strength. 
 */
void recover(queue <Character*> &winner);

/* Function: winner(queue Character obj1, stack Character loser, queue Character tally)
 * Description: take one player line up, the loser line up and the tally line up to decide which creature is 1st, 2nd and 3rd. 
 * Parameters: Character object1, loser object, tally object
 * Pre-Conditions: instantiated character objects in the queue, a loser stack, and a tally queue
 * Post-Conditions: will return the 1st, 2nd, adn third positions of the whole tournament. 
 */
void winner(queue <Character*> &player1, stack <Character*> &loser, queue <Character*> &tally);

/* Function: input(queue Character, # creatures)
 * Description: takes the character queue and the number of creatrues to create the line up for each playe
 * Parameters: Character queue, # creatures
 * Pre-conditions: instantiated character queue for player 1 and player 2
 * Post conditions: gives back the queue for each player
 */

void input(queue <Character*> &player1, int num_creatures);

int main(){
	
int num_creatures;// # of creatures in the tournaent
int attacker_num;// # delineating which creature the player picks for their line up 1 is goblin, 5 is shadow

	cout << "Player 1: How many creatures do you want in your line up, 4 being the least and 10 the most?\n";
	cin >> num_creatures;
	while(num_creatures >10 || num_creatures <=3){
		cout << "You must enter more than 3 creatures in your line up and less than 10. Enter in the # of creatures again\n";
		cin >> num_creatures;
	}

// Initiating queue for Characters. Placing into input function for generation fo lineup
   	queue<Character*> player1;
	queue<Character*> player2;
	cout << "Player 1, pick your line up\n";
	input(player1, num_creatures);
	cout << "Player 2, pick your line up\n";
	input(player2, num_creatures);

// Creating a stack for all the losers
	stack<Character*> loser;
// Combat between the two lineups (the front creature of each lineup battles the other creature)
	do{
	do{// do this loop of combat until one creatures strength is below 0 or if above 50 (reptile keeps getting more and more powerful w. each round) 
	   round(player1, player2);
           round(player2, player1);
        }while(player1.front()->getStrength() >0 && player2.front()->getStrength() >0 && player1.front()->getStrength() <50 && player2.front()->getStrength()<50);
	if(player1.front() ->getStrength() >= player2.front()->getStrength()){// if the player in the front wins the ccombat then put that player back into the line up. Have them go through recovery function to regain strength. The other player goes into the loser stack
		recover(player1);
		player1.push(player1.front());
		player1.pop();
		loser.push(player2.front());
		player2.pop();
		}
	else	{
		recover(player2);
                player2.push(player2.front());
                player2.pop();
                loser.push(player1.front());
                player1.pop();		
		}
	}while(!player1.empty() && !player2.empty());// do until one queue is totally empty

// creating queue for characters who will be popped out in order to tabulate who will be first second or third. 
	queue<Character*> tally;

	winner(player1, loser, tally);// winner function if player 1 is winner. Only one of these will display
	winner(player2, loser, tally);// winner function if player 2 is winner

// Displaying the tally for each team 
int tallyp1=0;// tally for player 1 line up
int tallyp2=0;// tally for player 2 line up

	while(!loser.empty()){// Calculating points for player 1 and player 2 by tabulating total strenght left in the team.
		if(loser.top() -> getTeam() ==1)
		tallyp1 += loser.top() ->getStrength();
		else
		tallyp2 += loser.top() ->getStrength();
	loser.pop();
	}

	while(!player1.empty()){
		tallyp1 += player1.front() ->getStrength();
		player1.pop();
	}

        while(!player2.empty()){
                tallyp2 += player2.front() ->getStrength();
                player2.pop();
        }
        while(!tally.empty()){
                if(tally.front() -> getTeam() ==1)
                tallyp1 += tally.front() ->getStrength();
                else
                tallyp2 += tally.front() ->getStrength();
        tally.pop();
        }	

	cout << "Score for player 1 is " << tallyp1 << endl;
        cout << "Score for player 2 is " << tallyp2 << endl;	

	
return 0;
}

void input(queue <Character*> &player1, int num_creatures){
int attacker_num;// used to designate creatures (1 is goblin, 5 is shadow)
	 for(int i=0; i<num_creatures; i++){
           cout << "Enter in the line up for your creatures. Pick a number between 1 and 5 signifying the following: Goblin =1, Barbarian =2, Reptile =3, Blue =4, Shadow=5\n";
           cin >> attacker_num;
           while(attacker_num<1 || attacker_num>5){// if else statements for picking characters and then pushing them into queue
                cout<< "You must enter in a number between 1 and 5. Enter again.\n";
                cin >> attacker_num;
                }

           if( attacker_num ==1){
                cout << "You picked Goblin for attacker\n";
                player1.push(new Goblin());}
           else if(attacker_num ==2){
                cout << "You picked Barbarian for attacker\n";
                player1.push(new Barbarian());}
           else if(attacker_num==3){
                cout << "You picked Reptile for attacker\n";
                player1.push(new Reptile());}
           else if(attacker_num==4){
                cout << "You picked Blue for attacker\n";
                player1.push(new Blue());}
           else if(attacker_num==5){
                cout << "You picked Shadow for attacker\n";
                player1.push(new Shadow());}
        }
}

int round(queue <Character*> &object1, queue<Character*> &object2){// objects from the input function are passed to this function

int combat_attack;//attacker dice roll
int combat_defense;// defenders dice roll
int combat_damage;// attackers dice - defenders dice - defenders armor
int combat_strength;// original strength points - combat_damage

// setting team values for each character that goes through the round of fighting
	if(object1.front() ->getTeam()==0)
		object1.front() ->setTeam(1);
	if(object2.front() ->getTeam()==0)
		object2.front() -> setTeam(2);

//**** generating combat attack adn defnese
        object1.front() -> setAttack();
        combat_attack = object1.front()->getAttack();// 11/18 changed form set to get
        // combat defense value 
        object2.front() ->setDefense();
        combat_defense = object2.front()->getDefense();// 11/18 change to get
        // setting achilles value for subsequent rounds
        if(object1.front()->getType() == "Goblin" && object1.front()->getAttack() == 12)
               object2.front()->setAchilles(true);// When fignting w goblin attack ability for next round is halved

// settign shadow values and combat damage values
        if(object2.front()->getType() == "Shadow")// Shadow - 50% chance that no damage
                combat_damage = (rand()%1)*(combat_attack - combat_defense);
        else
                combat_damage = (combat_attack - combat_defense) - object2.front()->getArmor();

// final comat strength vlaue
        combat_strength  = (object2.front()->getStrength() - combat_damage);
        object2.front()->setStrength(combat_strength);// setting strenght as new strenght value

return combat_strength;
}
void recover(queue<Character*> &winner){
float multiplier;// multiplier to be used to assign either half or quarter recovery to the character that's back in the lineup. 
	if(rand()%1==0)
		multiplier = .5;
	else
		multiplier = .25;
	
	if(winner.front()->getType() == "Goblin")
		winner.front()->setStrength(multiplier *8);
	else if(winner.front()->getType() == "Barbarian")
                winner.front()->setStrength(multiplier *12);
        else if(winner.front()->getType() == "Reptile")
                winner.front()->setStrength(multiplier *18);
        else if(winner.front()->getType() == "Blue")
                winner.front()->setStrength(multiplier *12);
        else if(winner.front()->getType() == "Shadow")
                winner.front()->setStrength(multiplier *12);      
}      

void winner(queue<Character*> &player1, stack<Character*> &loser, queue<Character*> &tally){
// this funciton issues out a statement of whos' winner, 2nd and 3rd place
        if(player1.size() >=3){
                cout << "First place in tournament is " << player1.front() ->getType() << " from team " << player1.front() ->getTeam() << endl;
                tally.push(player1.front());
                player1.pop();
                cout <<  " and second place is " << player1.front() ->getType() << " from team " << player1.front() ->getTeam() << endl;
                tally.push(player1.front());
                player1.pop();
                cout <<  " and third place is " << player1.front() ->getType() << " from team " << player1.front() ->getTeam() << endl;
        }else if(player1.size() >=2){
               cout << "First place in tournament is " << player1.front() ->getType() << " from team " << player1.front() ->getTeam() << endl;
                tally.push(player1.front());     
                player1.pop();
                cout <<  " and second place is " << player1.front() ->getType() << " from team " << player1.front() ->getTeam() << endl;
                cout << " third place is " << loser.top() ->getType() << " from team " << loser.top() ->getTeam() << endl;
        }else if(player1.size() >=1){
              cout << "First place in tournament is " << player1.front() ->getType() <<" from team " << player1.front() ->getTeam() << endl;
               cout << " second place is " << loser.top() ->getType() << " from team " << loser.top() ->getTeam() << endl;
                tally.push(loser.top());
                loser.pop();
                cout << " third place is " << loser.top() ->getType() << " from team " << loser.top() ->getTeam() << endl;
        }
	else if(player1.size() >=0){
		cout << endl;
	} 
}
                   
