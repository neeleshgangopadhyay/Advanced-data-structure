#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<cctype>
#include<cstdlib>

using namespace std;


struct Node
{
	int data;
	struct Node * next;
};

 struct Node * head =NULL;
 struct Node * temp;


void printlist(struct Node * node)
{
   struct Node * node = head;
   while(node != NULL)
   {

   	  cout<<node->data<<"";
   	  node = node-> next;

   }
}
void enterdata()
 {

    temp = new node();

	int data;

	cin>>data;

	temp->data = data;
	temp -> next= NULL;
    if(head == NULL)
      head = temp;
    else
      {
         temp->next = head;
         head = temp;
      }			
   }
 struct Node *reverse (struct Node *head, int k) 
{ 
    struct Node* current = head; 
    struct Node* next = NULL; 
    struct Node* prev = NULL; 
    int count = 0;    
      
    
    while (current != NULL && count < k) 
    { 
        next  = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        count++; 
    } 
      
    
    if (next !=  NULL) 
       head->next = reverse(next, k);  
  
   
    return prev; 
} 
 int main()
 {
   int k = 0;
   cout<<"Enter the data to be enterd in the list"<<endl;
   enterdata();
   cout<<"enter the number of element you want to reverse"<<endl;
   cin>>k;
   reverse(head,k);
   printlist();
   return 0;






 }