/*
 *  * Program Filename: main.cpp coupled w/ encryption.h and main.cpp and makefile
 *  ** Author: Danish Iqbal
 *  ** Date: 11/1/14
 *  ** Description: Takes message from file and encrypts it if user want substitution or transpoe
 *   sncrytion
 *   ** Input: message from file
 *   ** Output: Encrypted message
 *   *******************************************************************/

#include "encryption.h"
 

int main(){

	fstream decodeFile;// input file name
	decodeFile.open("decodefile.txt");
        string message;//  input message that will be later encrypted

	cout << "Processing the message you'd like encrypted\n";
        getline(decodeFile, message);

	string type;// type (either s or t for substitution or transposition)
	cout << "What type of encryption do you want? Select 's' for susbtitution or 't' for transposing\n";
	cin >> type;
	
	while(type != "s" && type !="t"){
                cout << "Only enter in s or t\n";
                cin >> type;
	}
	
	if(type == "s"){
	   Substitution line;
	   line.setInput(message);
	   cout <<"If substitution, what integer between 0 and 26 do you want it to shift by? \n";
	   int shift_main;
	   cin >> shift_main;
	   line.setShift(shift_main);
	   cout << "Your substituted message is " << line.dedupe() << endl;
	}
	else{
	   Transpose line;
	   line.setInput(message);
	   cout << "If transposition, what is your key \n";
	   int keyval;// your key 
	   cin >> keyval;
	   while(keyval/100 > line.length()){
		cout << "Only enter in a key who's size is less than the lenght of your mesage";
		cin >> keyval;
		}
	   line.setKey(keyval);
	   cout << "Your transposed message is " << line.transposed() << endl;
	}

return 0;
}
