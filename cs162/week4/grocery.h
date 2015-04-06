#include<fstream>
#include<iostream>
#include<string>

// I'm not going to comment on class get and set functions since it's self explanatory. 

using namespace std;

class Grocery
{
        string name;
	string unit;
	int quantity;
	float price;
	char remove;
public:
        string getName() {return name;}
	string getUnit() {return unit;}
	int getQuantity() {return quantity;}
	float getPrice() {return price;}
	char getRemove() {return remove;}	

        void setName(string n){name = n;}
	void setUnit(string u){unit = u;}
	void setQuantity(int q){quantity = q;}
	void setPrice(float p){price = p;}
	void setRemove(char ch){remove = ch;}
//reading data from file        
        void load(ifstream &inFile);
//storing data
        void store(ofstream &outFile);

//Constructor which takes in blanks or 0s as values of object 
	Grocery(string name ="", string unit = "", int quantity = 0, float price = 0, char remove= 0);

// Fucntion to display characterics of objects. See the fucntions in the header to see how this will come about through serialization. 
void display(){
	cout << "Name: "<< name << endl;
	cout << "Unit of measurement: "<< unit << endl;
	cout << "Quantity: "<< quantity << endl;
	cout << "Price per unit: " << price << endl;
	}
};
