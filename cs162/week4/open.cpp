#include "grocery.h"

int main(){

	const int TOTAL_ITEMS = 1;
	Grocery items[TOTAL_ITEMS];

	ifstream inFile("Grocerytest.txt", ios::binary);
	
	if(!inFile){
		cout << "Input file can't be opened\n";
	}
	
	for(int k=0; k<TOTAL_ITEMS; k++)
	    items[k].load(inFile);
        for(int k=0; k<TOTAL_ITEMS; k++)
            items[k].display();	
	
	inFile.close();

return 0;
}

