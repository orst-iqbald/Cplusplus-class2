#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Dice
{
public:
 Dice();
 Dice( int numSides);
 virtual int rollDice() const;
protected:
 int numSides;
};

Dice::Dice()
{
 numSides = 6;
 srand(time(NULL)); // Seeds random number generator
}

Dice::Dice(int numSides)
{
 this->numSides = numSides;
 srand(time(NULL)); // Seeds random number generator
}

int Dice::rollDice() const
{
 return (rand() % numSides) + 1;
}
//////
class LoadedDice:public Dice
{
public:
 LoadedDice();
 LoadedDice(int numSides);
 virtual int rollDice() const;
};

int LoadedDice::rollDice() const{
	if(rand()%2 == 1)
		return numSides;
	else
		return(rand() % numSides) +1;
}
LoadedDice::LoadedDice(){
 numSides = 6;
}
LoadedDice::LoadedDice(int numSides){
 this->numSides = numSides;
}


// Take two dice objects, roll them, and return the sum
int rollTwoDice(const Dice& die1, const Dice& die2)
{
return die1.rollDice() + die2.rollDice();
}

int main(){
	ofstream diceFile, loadedFile;
	diceFile.open("dice.csv");
	loadedFile.open("loaded.csv");


// Creation of dice 1 and 2

	Dice dice1(8);
	Dice dice2(10);

	cout << "This is dice 1 rolling " << dice1.rollDice() << endl;
	cout << "This is dice 2 rolling " << dice2.rollDice() << endl;

	for(int i=0; i<10; i++){
	cout << "This is the sum both dices rolling on attempt " << i << " " << rollTwoDice(dice1, dice2) << endl;
	}

// Creation of loaded dice
	LoadedDice ldice1(8);
	int roll;
	int dice_sum;

// Rolling regular dice and placing into csv file        
        for(int i=0; i<100; i++){
        roll = dice1.rollDice();
        cout<< "This is LoadedDice1 rolling " << roll << endl;
        diceFile << roll <<",";
        dice_sum += roll;
        }

// Rolling loaded dice and placing into csv file
	dice_sum =0;
	for(int i=0; i<100; i++){
	roll = ldice1.rollDice();
	cout<< "This is LoadedDice1 rolling " << roll << endl;
	loadedFile << roll <<",";
	dice_sum += roll;	
	}
	

return 0;
}
