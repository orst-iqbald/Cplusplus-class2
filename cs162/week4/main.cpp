/*********************************************************************
 Program Filename: Assignment 2 (main.cpp)- accompanied w/ Grocery.cpp, Grocery.h, Grocerytest.dat
 Author:Danish Iqbal
 Date: 10/20/14
 Description: Program to take in user gnerated grocery list and give user option to edit or remove items and display/ store them into exteral file
 Input: Built in sample grocery list and user generated grocery list
 Output: Grocerytest.dat a file which saves your grocery list and can read from it. 
 *********************************************************************/


#include "grocery.h"

/* Function: edit()
 * Description: Takes in Grocery class object array as well as the amount of objects in array and allows user to edit them
 * Parameters: Grocery class object array as well as the number of objects in the array
 * Pre-condition: call to edit function, solicited from user
 * Post-condition: edits every field of file
 */
void edit(Grocery[], int);

/* Function: remove_item()
 * Description: akes in Grocery class object array as well as the amount of objects in array and allows user to remove them by matching it to the name
 * Parameters: Grocery class object array as well as the number of objects in the array
 * Pre-condition: call to remove function, solicited from user
 * Post-condition: turn on the remove_item flag in the object every field of file
*/
void remove_item(Grocery[], int);

/* Function: storeOutput()
 * Description: stores Grocery object array into external file
 * Parameters: Grocery objects and # of objects
 * Pre-condition: filled grocery object, external file, remove_item flag marked no
 * Post-condition: storing of grocery objects array into file
 */
void storeOutput(Grocery[], int);

/* Function: storeOutput()
 * Description: loads  Grocery object array form external file for display onto program screen
 * Parameters: Grocery objects and # of objects
 * Pre-condition: filled grocery object, external file, remove_item flag marked no
 * Post-condition: loading of grocery objects array from file
  */
void loadInput(Grocery[], int);


int main(){
// Creating a sample list through an array of Grocery objects. notice how the remove item flag is marked n
	Grocery sample_items[] =
		{ Grocery("apple", "oz", 4, 1.88, 'n'), 
		  Grocery("banana", "lbs", 5, 4.78, 'n'), 
		  Grocery("grapes", "boxes", 17, 3.89, 'n')
		};

	int total_items_entry;// total item that user is placed to ask in addition to  sample items
	cout << "Let's create a grocery list. There's already a sample list buit in of three items. How many more items do you want on your list?\n";
	cin >> total_items_entry;

// Creation of Grocery objects items array
        int total_items = 3 + total_items_entry;// adding user input items to sample items for grocery items array
	Grocery items[total_items];// Declaration of items array of grocery items

// Creation of values for later input into Grocery objects items array
	string n, u; // string for get Name and get Unit
	int q;// int for quantity
	float p;// float for price
	char r; // characeter for removal flag

// For loop for inputting samples items into the Grocery objects items array
        for(int i=0; i<3; i++){// this places in sample array of item into items array that user will enter grocery items into
                n = sample_items[i].getName();
		u = sample_items[i].getUnit();
		q = sample_items[i].getQuantity();
		p = sample_items[i].getPrice();
	   items[i].setName(n);
           items[i].setUnit(u);
           items[i].setQuantity(q);
           items[i].setPrice(p);
           items[i].setRemove('n');	 
	}

// reopening items array for user to input their items into items array
 	for(int i=3; i<total_items; i++){// This isin array that asks users to input the items they've declared for the gorcery list. asks for items, units, quanitty, and price
		cout << "Enter in item name\n";
		getline(cin, n);
		cout << "Enter in unit of measurement\n";
		cin >> u;
		cout << "Enter in quantity\n";
		cin >> q;
		cout << "Enter in price\n";
		cin >> p;
   	   items[i].setName(n);
	   items[i].setUnit(u);
	   items[i].setQuantity(q);
	   items[i].setPrice(p);
	   items[i].setRemove('n');
	}

// Declaration of total sum integer to give total price of grocery items in list
        float total_sum;// Total price of grocery list. Loop below calculates and output onot sceen
        for(int i=0; i<total_items; i++){
                total_sum += ((items[i].getPrice())*(items[i].getQuantity()));
        }
	cout << "The total sum of all your items is " << total_sum << endl;	

// Storing and loading (displaying) the items yo've input onto program sceen
	cout << "Saving and storing your grocery list as it currently stands\n";
	storeOutput(items, total_items);
        loadInput(items, total_items);

// Three choices now:  Edit, or Remove items through these fucntions. After this the list is displayed
	string choice;// declaration fo variable for you to pick edit or remove
	cout << "What do you want to do to the list? Edit it, or Remove items that you've bought? Pick between 'edit' or  'remove' ";
	cin >> choice;
	// Do while loop for enters in right choice (eid ot remove)
	if((choice != "edit" && choice != "remove"))
		do{
		  cout << " You must pick btween edit or remove\n";
		  cin.ignore(1000, '\n');
		  getline(cin, choice);
 	      }while(choice != "edit" && choice != "remove");
	// if-else statemet calling edit or remove function. You have to pick one! After than the final list is displayed. 
	if(choice == "edit")
		 edit(items, total_items);
	else
		 remove_item(items, total_items);
	// storing itmes into an external file andthen loading them onto program file. 	
        cout << "Saving and storing your grocery list as it currently stands\n";
        storeOutput(items, total_items);
        loadInput(items, total_items);

return 0;
}

// Function to edit objects in the Grocery list
void edit(Grocery items[], int total_items)
{
        string entry;// string to see whic item you want to edit
	string n, u;// Same declaration as above for inputting in edits to the item fields
        int q;
        float p;
        char r;

        string edit_answer;// string, yes or no for if you want to edit another item. in do while loop
        
// Do while loop for edit answer if you want to eidt the tiem again. 
	do{
        cout << "Which item name do you want to edit\n";
        cin.ignore(1000, '\n');
	getline(cin, entry);
  
	int i;      
	for(i=0; i<total_items; i++){// loop for entry of each field of item you wna tot edit
                if(items[i].getName() == entry){
                cout << "Enter in edited name item name\n";
                getline(cin, n);
                cout << "Enter in edited unit of measurement\n";
                cin >> u;
                cout << "Enter in edited quantity\n";
                cin >> q;
                cout << "Enter in edited price\n";
                cin >> p;
           	  items[i].setName(n);
           	  items[i].setUnit(u);
           	  items[i].setQuantity(q);
           	  items[i].setPrice(p);
		break;
                }
        }
	if(i==total_items && items[i].getName() != entry) // if the item is not found then cout this message
		cout << "Invalid entry. Enter a valid item name\n";

        cout << "Do you want to edit your list? Enter in 'y' or 'n'\n";
        cin >> edit_answer;
        } while (edit_answer == "y");
}

// Funcitno for removing items
void remove_item(Grocery items[], int total_items)
{

        string entry; // string for if you want to remove another item (y or n)
	string remove_answer;// string for which item you wan to remove

	// do-while loop for if you want to remove more items
        do{
        cout << "Which items do you want to remove from the grocery list?\n";
       	cin.ignore(1000, '\n');
	getline(cin, entry);
        
	int i;
	// in this loop each items that been indicated to be removed, the remove item flag is turned on to yes
	for(i=0; i<total_items; i++){
                if(items[i].getName() == entry){
                items[i].setRemove('y');
                break;
		}
	}        
        if(i==total_items && items[i].getName() != entry)
                cout << "Invalid entry. Enter a valid item name\n";
        
        cout << "Do you want to remove another item? Enter in 'y' or 'n' \n";
        cin >> remove_answer;
        } while(remove_answer == "y");
	
}

// Funciton to store output into external file. 
void storeOutput(Grocery items[], int total_items){
        ofstream outFile("Grocerytest.txt", ios::binary);
        if(!outFile){
                cout << "The output file can't be opened";
        }
        for(int i=0; i<total_items; i++){// only input items where remove item flag is no
                if(items[i].getRemove() != 'y'){
                items[i].store(outFile);
        }
	}
        cout << "Data has been written to file\n ";

        outFile.close();
}

// Function to load items from external file onto program
void loadInput(Grocery items[], int total_items){
        ifstream inFile("Grocerytest.txt", ios::binary);

        if(!inFile){
                cout << "Input file can't be opened\n";
        }

        for(int k=0; k<total_items; k++)// only load and display itmes for which remove item flat isnt' on. 
	    if(items[k].getRemove() != 'y'){
            items[k].load(inFile);}
        for(int k=0; k<total_items; k++)
	    if(items[k].getRemove() != 'y'){
            items[k].display();}

        inFile.close();
}

