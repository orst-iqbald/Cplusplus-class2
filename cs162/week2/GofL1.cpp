/*****
 * Program Filename - Assignment 1, CS 162
 * Author: Danish Iqbal
 * Date: 10/4/14
 * Input: User to input initial cell to shade in for Game of life
 * Output: Board shaded according to Game of Life Rules
 */

#include <iostream>
#include <string>
using namespace std;

/*Function: printBoard
 * Description: This function prints the Game of Life board 
 * Parameters: board - 80x22 array
 * Pre- Conditions: array
 * Post - Condition: cout array
 */
void printBoard(int b[][22]);

/* Function: sumBoard
 * Description: This function sums the neighboring cells around the cell in question
 * Parameters: Game board array and the position of the current iteration (i, j)
 * Precondition: In a for-loop the program needs to be centered in on one cell
 * Post-conditions: sum of neighboring cells around cell (i,j)
 */
int sumBoard(int b[][22], int i, int j);

int main(){
	int board[80][22];// Creating of game board array 80 x 22

// Creating of game board array filled with zeros
	for(int i=0; i<80; i++){
		for(int j=0; j<22; j++)
		board[i][j] = 0;
	}

//Creation of mini, 3 x 3 board filled within the 80x22 board that filled 1-9 indicating cells that the user can choose to fill in
	int count =1;
	for(int i=1; i<4; i++){
		for(int j=1; j<4; j++){
		board[i][j] = count;
		count++;
 		}
	}

// Printing of game board array	
	printBoard(board);

// Command to users
	int elements;// indicates the cells that the user will shade in
	cout << "How many cells do you want to shade in for the initialization? Enter in a between 4 and 9.\n";
	while(elements <4 || elements > 9){
		cout << "You must enter a number between 4 and 9\n";
		cin >> elements;
	}

//This is where user picks which cells they'd like shaded in the 3 x 3 array
	cout << "Enter in " << elements << " different elements numbered 1 to 9. These will indicate the shaded cells\n";
	int userinputs[elements];// array that holds the number of the cells that the user wants to have shaded
	
	for(int i=0; i<elements; i++){
		cin >> userinputs[i];
		while(userinputs[i] <0 || userinputs[i] >10){
		   cout << "Enter in numbers 1 to 10 only\n";
		   cin >> userinputs[i];
		   }
		for(int x=0; x<i; x++){
			if(userinputs[i] == userinputs[x]){
			cout << "You can't enter the same input. Enter again\n";
			cin >> userinputs[i];
			}
		}
	}
	
// For each cell that the user has chosen, the loop below shades in those cells as 1
		for(int i=1; i<4; i++){
           	   for(int j=1; j<4; j++){
		      for(int u=0; u<elements; u++){
			if(board[i][j] == userinputs[u])
			   board[i][j] = 1;
		   	}
		   }	
		}		
// This shades in all cells that are not 1 as zeros (indicating that they werent' picked by the user in the 3 x 3 board numbered 1 to 9)
                for(int i=1; i<4; i++){
                   for(int j=1; j<4; j++){
			if(board[i][j] !=1)
			   board[i][j] =0;
			}
		}

	printBoard(board); // Printing a board for a view of the initial state
	string generation; // This will be used later to indicate whether the user wants to run the game for another generation

// Do-while loop for each generation of the Game
do{
	
//Implementing rules for Game of Life. The sumBoard function is a function that sums the neighboring cells and wil to be used to see whether the cell shoudl be occupied or unoccupied.
	for(int i=1; i<79; i++){
	   for(int j=1; j<21; j++){
		if((board[i][j]=1) && (sumBoard(board, i, j)-1)>3)// death if occupied and more than three neighbors 
		   board[i][j]=0;
		else if((board[i][j]=0) && (sumBoard(board, i, j)==3))// birth if unoccupied and exactly 3 nieghbors
		   board[i][j]=1;
		else if((board[i][j]=1) && (sumBoard(board, i, j)-1)<2)// death if less occupied and less than 2 neighbors
		   board[i][j]=0;
		}
		}
	cout << endl;

	printBoard(board);// Print board after each run

        cout<< " Do you want to create another generation? Enter in 'y' or' n'\n";
        cin >> generation;
	while(generation != "y" && generation != "n"){
                cout << "Enter in only y or n\n";
                cin >> generation;
        }

} while (generation == "y");
return 0;
}

int sumBoard(int b[][22], int i, int j){
	int sum= 0;
        for(int x=-1; x<=1; x++){// marker of the neighbors on x axis around cell
           for(int y=-1; y<=1; y++){// marker of neighbors on y axis around cell
	       sum = sum + b[i+x][j+y];
	}
	}
	return sum;
	}

void printBoard(int b[][22]){
        for(int i=0; i<80; i++){
                cout<< endl;
                for(int j=0; j<22; j++)
                cout << b[i][j];
        }
        cout << endl;
}
