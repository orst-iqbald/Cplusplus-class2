/*
 * Program Filename: Encryption.cpp coupled w/ encryption.h and main.cpp
** Author: Danish Iqbal
** Date: 11/1/14
** Description: Takes message from file and encrypts it if user want substitution or transpoe sncrytion
** Input: message from file
** Output: Encrypted message
*******************************************************************/

#include<fstream>
#include<iostream>
#include<string>
#include<stdio.h>
#include<string.h>
#include<sstream>

using namespace std;

class Encryption
{
protected:
   string input;// input message
public:
   Encryption() {setInput("");}// constructor
   void setInput(string eInput);
   string getInput() {return input;}
   int length();// length of input mesage
};

class Substitution: public Encryption
{
private:
   int shift;
public:
   void setShift(int sShift) {shift = sShift;}// shift of substituted message
   int getShift() {return shift;}
   string dedupe();// deduplicated message that will be encrypted
};

class Transpose: public Encryption
{
private:
   int key;// the key 
public:
   void setKey(int eKey) {key = eKey;}
   int getKey() {return key;}
   string transposed();// final encrypted message
};

