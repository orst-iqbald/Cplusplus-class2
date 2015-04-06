/*
* Program Filename: pointer2.cpp (From Lab 1, Question 2)
* Author: Danish Iqbal
* Date: 10/2/14
* Input: Input three integers
* Output: You get the smallest, middle, and largest integer back in that order
*/

#include <iostream>


/*
 * Function: getNumbers
 * Description: This functions gets the integers in pointer form
 * Parameters: Three pointers to integers
 * Pre-conditions: 3 integers
 * Post-conditions: Stores the numbers by asking user to enter them
 */
void getNumbers(int *num1, int *num2, int *num3);

/*
 * Function: sortNumbers
 * Descritpion: This sorts the integers that were input using an array
 * Parameter: Takes the references to the numbers that were placed into the previous function
 * Pre-conditions: Pointers to integers from prevoius funciotns
 * Post-conditions: Largest, Middle, and Smallest number
 */
void sortNumbers(int *num1, int *num2, int *num3);

int main(){
	int num1, num2, num3;// declaration ofthree integers to be used in the functions below
	
	getNumbers( &num1, &num2, &num3);//Asks user to input integers
	sortNumbers(&num1, &num2, &num3);// Sorts integers
	
	std::cout << "The smallest number is "<< num1 << ". The middle number is "<< num2 << ". The largest number is " << num3 << std::endl;

return 0;
}

void getNumbers(int *num1, int *num2, int *num3)
{
	std::cout << "Enter in 3 different numbers. Number 1:\n";
	std::cin >> *num1;
	std::cout << "Number 2:\n";
	std::cin >> *num2;
	std::cout << "Number 3:\n";
	std::cin >> *num3;

}

void sortNumbers(int *num1, int *num2, int *num3)
{
	int numarray[3];// Declaration of an array that will store in the three different integers

	numarray[0] = *num1;
	numarray[1] = *num2;
	numarray[2] = *num3;
	
	int smallest = numarray[0];// Declaration of smallest integer for sorting
	int largest = numarray[0];// Declaration of largest integer for sorting

	for(int i=0; i < 3; i++)
	   {
	   	if(smallest > numarray[i])
		   smallest = numarray[i];
		if(largest < numarray[i])
		   largest = numarray[i];
	   }
	int middle = (*num1 + *num2 + *num3) - (smallest +largest);// This is the middle number found by subtracting the smallest and largest numbers from the total set
	
	*num1 = smallest;// Re-assingment of values based on largest, smallest and middle.
	*num2 = middle;
	*num3 = largest;
}
