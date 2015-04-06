#include "grocery.h"

// class constructor for input of values. 
Grocery::Grocery(string name, string unit, int quantity, float price, char remove)
{
	this->name = name;
	this->unit = unit;
	this->quantity = quantity;
	this->price = price;
	this->remove = remove;
}
// store function that converts input into charcters so they can be written onto external file. follows serialization scheme
/* Fucntion: store()
 * Description: converts input of class objects into charactes and then reintrperts them into charactes and writes them onto file
 * Parameters: class objects parameters
 * Pre-conditions: class objects
 * Post-condition: conversion of inputs inot characters and then writing them onto the file
 */
void Grocery::store(ofstream &outFile)
{
	int nameLength = name.length();
	outFile.write(reinterpret_cast<char *>(&nameLength), sizeof(int));
	outFile.write(name.data(), nameLength);

        int unitLength = unit.length();
        outFile.write(reinterpret_cast<char *>(&unitLength), sizeof(int));
        outFile.write(unit.data(), unitLength);

	outFile.write(reinterpret_cast<char *>(&quantity), sizeof(quantity));
	outFile.write(reinterpret_cast<char *>(&price), sizeof(price));
	outFile.write(&remove, sizeof(remove));
}
// load function that converts each input into charcters so they can be written onto external file. follows serialization scheme
void Grocery::load(ifstream &inFile)
{
	const int BUFFER_SIZE = 256;
	static char buffer[256];

	int nameLength;
	inFile.read(reinterpret_cast<char *>(&nameLength), sizeof(int));
	inFile.read(buffer, nameLength);
	
	buffer[nameLength]= '\0';
	name = buffer;

        int unitLength;
        inFile.read(reinterpret_cast<char *>(&unitLength), sizeof(int));
        inFile.read(buffer, unitLength);

        buffer[unitLength]= '\0';
        unit = buffer;

	inFile.read(reinterpret_cast<char *>(&quantity), sizeof(quantity));
	inFile.read(reinterpret_cast<char *>(&price), sizeof(price));
	inFile.read(&remove, sizeof(remove));
}

