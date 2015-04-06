/*********************************************************************
 * ** Program Filename: lab3q2.cpp - Lab 3, Question 2 - accompanied w/ file1.txt, file2.txt and output.txt
 * ** Author:Danish Iqbal
 * ** Date: 10/18/14
 * ** Description: Program to merge sorted numbers in file 1 and 2 into numberical order in output file.
 * ** Input: file 1 and file 2 -- containing sorted number and no extra lines or non numberical characters
 * ** Output: output.txt file which has sorted adn merged number from files 1 and 2
 * *********************************************************************/

#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*********************************************************************
 * ** Function: openFile()
 * ** Description:  Opens various files (file1, file2, and output file)
 * ** Parameters: file(reference paramater), string (name of file)
 * ** Pre-Conditions: declration of file via fstream
 * ** Post-Conditions: Open files and returns faulty statement if opening file unsuceesful
 * *********************************************************************/
void openFile(fstream &file, string descr);
/*********************************************************************
 * ** Function: endLine()
 * ** Description: Places a dash at the end of input files so the last line can be read by the while loop 
 * ** Parameters: filename
 * ** Pre-Conditions: an opened file
 * ** Post-Conditions: gives you back a file w/ a dash at the end
 * *********************************************************************/
void endLine(fstream &file);

int main(){

// Declaration of input adn output files
	fstream file1, file2, outputFile;

//function to open files and another function to place dash at end of input files
	openFile(file1, "fileOne");
	endLine(file1);
	openFile(file2, "fileTwo");
	endLine(file2);
	openFile(outputFile, "Output");

// Declaration of variables for sorting through input files	
	string x1, y1, x2, y2;
	getline(file1, x1); // current value from file 1
	getline(file2, y1); // current value from file 2
	getline(file1, x2);// next value from file 1
	getline(file2, y2);// next value form file 2

//Sorting and merging algorithm. This looks at both files and compares one value from one file to two adjacent values from the other file. Based on where the value fits, it puts it after or before the values of the other file. Values form file 1 are x1 nad x2 and values from file 2 are y1 adn y2
	while(file1 || file2){
	if(file1 && file2){
	   if(x1 < y1 && y1 < x2){// the case where a y values is in the middle of two adjacent x values
		outputFile << "file 1-: " << x1 << endl;
		outputFile << "file 2-: " << y1 << endl;
		x1 = x2;
		y1 = y2;
		getline(file1, x2);
		getline(file2, y2);
		}
		else if(y1 < x1 && y1 < x2){// case where y value is followed by x values
		outputFile << "file 2--: " << y1 <<endl;		
		y1 = y2;
                getline(file2, y2);
		}
		else{// x1< y1 (and x1 < y2 - always the case) and case wehre x value followed by y values
		outputFile << "file1--: " << x1 <<endl;
                x1 = x2;
                getline(file1, x2);
		}
	    }
            if(file1 && !file2){// when file 2 ends just print in contents from file 1
		outputFile << "file1: " << x1 << endl;
		x1 = x2;
		getline(file1, x2);    
            }
	    if(!file1 && file2){// when file 2 ends just print content form file 1
		outputFile << "file 2: " << y1 << endl;
		y1 = y2;
		getline(file2, y2);
	    }
	}

return 0;
}

// Function to open files. I'm writing the files I've placed into this program so it's easier for you
void openFile(fstream &file, string descr)
{
	string fileName;
        cout << "Enter file's name for " << descr << " (write in file1.txt, file2.txt and output.txt in that order): ";
        cin >> fileName;

        file.open(fileName.data(), ios::in | ios::out | ios::app);
        if(!file){
                cout << "Can't open file "<< fileName;
                exit(1);
        }
}

// Function to place dash into input files and then it returns to beginning marker. 
void endLine(fstream &file)
{
        file << "-";
        file.clear();
        file.seekg(0L, ios::beg);
}
