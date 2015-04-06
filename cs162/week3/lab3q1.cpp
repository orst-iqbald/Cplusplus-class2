/* 
 * Program Filename: lab3q1.cpp - CS162 Lab2, Question 1
 * Name: Danish Iqbal
 * Date: 10/18/14
 * Description: Count characters and words in an input file (words.txt)
 * Input: Input file - words.txt. This is accompanied w/ this program
 * Output: Count of characters and words
 */

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

// declaration of file 
        ifstream inputFile;
        inputFile.open("words.txt");
// declaration of counters that will help us understand characters and words
	int space_counter=0;
	int char_counter=0;
	int punct_counter=0;
	int num_counter=0;
// declaration of character that will loop aroudn statement using while loop
	char ch;
	ch = inputFile.get();
// while loop that looks for spaces, alphabetic characters, punctuation, and numbers
	while(ch !=EOF){
	   if(isspace(ch))
		space_counter++;
           if(isalpha(ch))
                char_counter++;
	   if(ispunct(ch))
		punct_counter++;
	   if(isdigit(ch))
		num_counter++;
	ch = inputFile.get();// back to get
	}

	cout << "There are " << space_counter-1 << " spaces\n"; // space counter-1 = spaces
        cout << "There are " << space_counter-2 << " words in this file\n";// spaces-2 equal words
        cout << "There are " << char_counter << " alphabetic characters\n";	
        cout << "There are " << punct_counter << " punctuation marks\n";	
        cout << "There are " << num_counter << " digits\n";

return 0;
}
