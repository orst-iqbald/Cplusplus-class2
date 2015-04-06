/* Program Filename: Lab6.cpp (Lab 6 for Week 6 assingment)
 * Author: Danish Iqbal
 * Date: 11/9/14
 * Description: Linear and Binary search and sorts input from file
 * Input: 4 files
 * Output: Sorted results in 4 files, and position of number 5 in each
 */

#include<iostream>
#include<fstream>

using namespace std;
// Function: linear search through array
int linSearch(int list[], int size, int value);
// Function: sorting array into smallest to larges
void sortArray(int list[], int size);

int main(){

int number;// what output in file will be called

ifstream beginning, middle, end, none;// input files for reading random list
ofstream fil1, fil2, fil3, fil4;// output files for writing sorted number

int begin[20];// array for begin file
int mid[20];// array for middle file
int end_arr[20];// array for end file
int non[20];// array for none file
int i=0;// counter in arrays

// Opening files w/ randon # input
   beginning.open("beginning.txt");
   middle.open("middle.txt");	
   end.open("end.txt");
   none.open("none.txt");

// linear search for all 4 files
   while(beginning >> number){
 	begin[i] = number;
	i++;
   }
   i=0;
   while(middle >> number){
        mid[i] = number;
        i++;
   }
   i=0;
   while(end >> number){
	end_arr[i] = number;
	i++;
   }
   i=0;
   while(none >> number){
        non[i] = number;
        i++;
   }

// output of position from linear search from each file 

cout << "For beginning linear position is " << linSearch(begin, 20, 5) << endl;
cout << "For middle linear position is " << linSearch(mid, 20, 5) << endl;
cout << "For end linear position is " << linSearch(end_arr, 20, 5) << endl;
cout << "For none linear position is " << linSearch(non, 20, 5) << endl;	

// sorting
	sortArray(begin, 20);
	sortArray(mid, 20);
	sortArray(end_arr, 20);
	sortArray(non, 20);

// binary searc
string file1, file2, file3, file4;
int f1, f2, f3, f4;

	cout << "what 4 file names would you like your sortted output in? Press enter after each input\n";
	cin >> file1;
	cin >> file2;
	cin >> file3;
	cin >> file4;

	fil1.open(file1.c_str());
        fil2.open(file2.c_str());
        fil3.open(file3.c_str());
        fil4.open(file4.c_str());

	for(int i=0; i<20; i++){
	   	fil1 << begin[i] << endl;
                fil2 << mid[i] << endl;
                fil3 << end_arr[i] << endl;
                fil4 << non[i] << endl;
	}

cout << "For beginning binary position is " << linSearch(begin, 20, 5) << endl;
cout << "For middle binary position is " << linSearch(mid, 20, 5) << endl;
cout << "For end binary position is " << linSearch(end_arr, 20, 5) << endl;
cout << "For none binary position is " << linSearch(non, 20, 5) << endl;


return 0;
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
