/* Name: Lab7.cpp (Sorting and BigO)
 * Auuthor: Danish Iqbal
 * Date: 11/9/14
 * Description: Linear and Binary search and sorts input from file
 * Input: 4 files
 * Output: Sorted results in 4 files, and position of number 9 in each
 */
#include<time.h>
#include<iostream>
#include<fstream>
#include<cstdlib>

using namespace std;
// Function: fills in the files the user names w/ random output between 0 and 8. 9 is placed to be search for later
/*********************************************************************
 * ** Function: fillin
 * ** Description: fills in files w/ randome number between 0 to 8 that the user designates
 * ** Parameters: file and length (how many interegers you wan tin theant in the file)
 * ** Pre-Conditions: files and input for length
 * ** Post-Conditions: fills in files youv picked
 * *********************************************************************/
void filin(fstream& file, int length);
// Function: linear search through array
/*********************************************************************
 * ** Function: linSearch
 * ** Description: Does linear search on array
 * ** Parameters: array, size adn value your're search for 
 * ** Pre-Conditions:array and user input for size and value
 * ** Post-Conditions: returns the position of the vlues you're looking ofr
 * *********************************************************************/
int linSearch(int list[], int size, int value);
// Function: sorting array into smallest to larges
/*********************************************************************
 * ** Function:sortArray
 * ** Description: sorts the array into smallest to largest
 * ** Parameters:array and size
 * ** Pre-Conditions: all integers need to be in array
 * ** Post-Conditions: a sorted array
 * *********************************************************************/
void sortArray(int list[], int size);
// funtion: fills in an array from the file output to be used for sorting and binary search later on
/*********************************************************************
 * ** Function: fill_array
 * ** Description: fills in the values from the files into an array
 * ** Parameters: file, filemname, array, length
 * ** Pre-Conditions: files with names
 * ** Post-Conditions: Array generated form file input
 * *********************************************************************/
void fill_array(fstream& file, string filename, int arr[], int length);
// Funciton for ginary search
/*********************************************************************
 * ** Function: binarySearch
 * ** Description: does a bubble sort on a given array
 * ** Parameters: array, size adn value
 * ** Pre-Conditions: sorted array
 * ** Post-Conditions: position of value
 * *********************************************************************/
int binarySearch(int list[], int size, int value);

int main(){
fstream fil1, fil2, fil3, fil4;// Files in fstream
string file1, file2, file3, file4;// File string variobles
int f1, f2, f3, f4;// # of integers user wants in each file

// Asking for file names and the # of integers to fill in
        cout << "Enter in the file name for the file w/ 9 near the beginning\n";        
	cin >> file1;
        cout << "Enter in the file name for the file w/ 9 near the middle\n";
        cin >> file2;
        cout << "Enter in the file name for the file w/ 9 near the end\n";
        cin >> file3;
        cout << "Enter in the file name for the file w/o any 9\n";
        cin >> file4;


        cout << "Enter in the number of randomized digits you want in file " << file1 <<endl;
        cin >> f1;
        cout << "Enter in the number of randomized digits you want in file " << file2 <<endl;
        cin >> f2;
        cout << "Enter in the number of randomized digits you want in file " << file3 <<endl;
        cin >> f3;
        cout << "Enter in the number of randomized digits you want in file " << file4 <<endl;
        cin >> f4;

// Opening files to begin input of random #s 0 to 8
        fil1.open(file1.c_str(), ios::out);
        fil2.open(file2.c_str(), ios::out);
        fil3.open(file3.c_str(), ios::out);
        fil4.open(file4.c_str(), ios::out);
	
// Creating arrays for later sorting and bineary search
	int begin[f1+1];
	int mid[f2+1];
	int end_arr[f3+1];
	int non[f4];

// Filling in 9 in appropriate spots and using funciton fillin to place in random #s 0 to 8 in the files
        int nine =9;
	fil1 << nine << endl;
	filin(fil1, f1);
        filin(fil2, f2/2);
	fil2 << nine << endl;
	filin(fil2, f2/2);
        filin(fil3, f3);
	fil3 << nine << endl;
        filin(fil4, f4);

	fil1.close();
        fil2.close();
        fil3.close();
        fil4.close();

// Taking output from files and filling an array with it for later sorting
	fill_array(fil1, file1, begin, (f1+1));
        fill_array(fil2, file2, mid, (f2+1));
        fill_array(fil3, file3, end_arr, (f3+1));
        fill_array(fil4, file4, non, (f4));

// output of position from linear search from each file 
clock_t start;
long double duration;

start = clock();
cout << "For beginning linear position is " << linSearch(begin, (f1+1), 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

start = clock();
cout << "For middle linear position is " << linSearch(mid, (f2+1), 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

start = clock();
cout << "For end linear position is " << linSearch(end_arr, (f3+1), 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

start = clock();
cout << "For none linear position is " << linSearch(non, (f4), 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took " << duration << " second\n";

// output of position after sorting and binary search
start = clock();
        sortArray(begin, (f1+1));
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "for beginning sorting it took" << duration << "second\n";

start = clock();
cout << "For beginning binary position is " << binarySearch(begin, f1+1, 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took" << duration << "second\n";

start = clock();
        sortArray(mid, f2+1);
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "for mid sorting it took" << duration << "second\n";

start = clock();
cout << "For middle binary position is " << binarySearch(mid, f2+1, 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took" << duration << "second\n";

start = clock();
        sortArray(end_arr, f3+1);
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "for end sorting it took" << duration << "second\n";

start = clock();
cout << "For end binary position is " << binarySearch(end_arr, f3+1, 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << " it took" << duration << "second\n";

start = clock();
        sortArray(non, f4);
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "for none sorting it t ok" << duration << "second\n";

start = clock();
cout << "For none binary position is " << binarySearch(non, f4, 9) << endl;
duration = (clock() - start)/ (long double) CLOCKS_PER_SEC;
cout << "it took" << duration << "second\n";

return 0;
}

void filin(fstream &file, int length)
{
	int f;
        for(int i=0; i<length; i++){
		f = rand()%8;
                file << f << endl;
	}
}

void fill_array(fstream &file, string filename, int arr[], int length)
{
        int input;
	int i=0;
        file.open(filename.c_str(), ios::in);
        while(file >> input){
	     arr[i] = input;
	     i++;
	}
}

int linSearch(int list[], int size, int value)
{
int index =0;
int position = 0;
bool found = false;

        while(index < size && !found)
        {
           if(list[index]==value){
                found = true;
                position = index;
           }
        index++;
        }
        return position;
}

void sortArray(int list[], int size){
int temp;
bool swap;

   do{
        swap = false;
        for(int count=0; count <(size - 1); count++)
        {
           if(list[count] > list[count +1])
           {
                temp = list[count];
                list[count] = list[count +1];
                list[count +1] = temp;
                swap = true;
           }
        }
   } while (swap);
}

int binarySearch(int list[], int size, int value){
int first=0, last = size-1, middle, position = -1;
bool found = false;

while(!found && first <=last)
{
   middle = (first + last)/2;
   if (list[middle] == value)
   {
        found = true;
        position = middle;
   }
   else if (list[middle] > value)
        last = middle -1;
   else
        first = middle +1;
   }
   return position;
}
  
        
