#include <iostream>

using namespace std;

struct ListNode
{
   int value;
   ListNode *next;
   // Constructor
   ListNode(int value1, ListNode *next1 = NULL)
   {
	value = value1;
	next = next1;
   }
};


//void push(int number, ListNode *position);
//int peek()
//void pop()

void push(ListNode *head, int number);
int main(){
	
	ListNode *head;// = new ListNode(13.5);
	head = new ListNode(12.5);

//	first = new ListNode(1, NULL);
//	push(2, first);
	push(head, 14);	
	cout << head ->value << endl;
        cout << head->next->value << endl;
        cout << head->next->next->value << endl;


return 0;
}
void push(ListNode *head, int number){
int old_value = head->value;
	ListNode *n_head = new ListNode(number);
	n_head = new ListNode(old_value, n_head);
}
/*
void push(int number, ListNode *position)
{
	ListNode *second;
	second = new ListNode(number, NULL);
	position ->next = second;
}
*/
