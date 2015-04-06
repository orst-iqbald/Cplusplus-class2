/* Assingment: Lab8.cpp
 * Name: Danish Iqbal
 * Date: 11/20/14
 * Description: Maze program. user stars at A and has to make it through to he 3x3 matrix to I
 * Input: User to input rooms
 * OUtput: Completion of maze
 */


#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
        char letter;
        ListNode *north;
        ListNode *east;
        ListNode *west;
        ListNode *south;
        // Constructor
       ListNode(char letter1, ListNode *north1 = NULL, ListNode *east1 = NULL, ListNode *west1 = NULL, ListNode *south1 = NULL)
                {
                letter = letter1;
                north = north1;
                east = east1;
                west = west1;
                south = south1;
                }
};
// This funtion give you the list of possilbe directions form the room your'e in
void direction(ListNode *ptr);

int main(){
// Creation of rooms A through I
        ListNode *A;
        ListNode *B;
        ListNode *C;
        ListNode *D;
        ListNode *E;
        ListNode *F;
        ListNode *G;
        ListNode *H;
        ListNode *J;
// Constructor of pointers for each room and letters fo each room
        J = new ListNode('j', F, NULL, H, NULL);
        H = new ListNode('h', E, J, G, NULL);
        G = new ListNode('g', D, H, NULL, NULL);
        F = new ListNode('f', C, NULL, E, J);
        E = new ListNode('e', B, F, D, H);
        D = new ListNode('d', A, E, NULL, G);
        C = new ListNode('c', NULL, NULL, B, F);
        B = new ListNode('b', NULL, C, A, E);
        A = new ListNode('a', NULL, B, NULL, D);
// Initiation of pointer that will traverse through maze as user goes throug it. 
        ListNode *traverse = A;
        string path;// for user to enter direction
        string labels;

        cout << " Do you want labels, meaning do you want to know the room you're in" << endl;
        cin >> labels;
                while(labels != "y" && labels != "n"){
                  cout << "You must enter in a y or an n " << endl;
                  cin >> labels;
                }

        cin.ignore();
// Start of maze will happen in room A
        cout << " You're starting our in box A" << endl;
// Maze will end once you reach room I
        while(traverse->letter != 'j'){
        //        if(labels != "n"){
		cout << " Now you're in box ** " << traverse -> letter << endl;
          //      }
               // cin.ignore(20, '\n');

                direction(traverse);

                cout << "which direction do you wanto to go in" << endl;
		getline(cin, path);

                if(path == "north")
                   traverse = traverse -> north;
                   else if(path == "east")
                   traverse = traverse ->east;
                   else if(path == "west")
                   traverse = traverse ->west;
                   else if(path == "south")
                   traverse = traverse ->south;

        }

        cout << "Good job! You did it and got out of the maze" << endl;
	
	delete A;
	delete B;
	delete C;
	delete D;
	delete E;
	delete F;
	delete G;
	delete H;
	delete J;

return 0;
}
void direction(ListNode *ptr)
{
        if(ptr->north != NULL)
                cout << "You can go north " << endl;
        if(ptr->south != NULL)
           cout << "You can go south " << endl;
        if(ptr->east != NULL)
           cout << "You can go east " <<endl;
        if(ptr->west != NULL)
           cout << "You can go west to " << endl;
}
