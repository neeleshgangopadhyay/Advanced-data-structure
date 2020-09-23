#include<bits/stdc++.h>
#include<iomanip>
#include<inttypes.h>


using namespace std;

class Node
{

   public:
   	int data;
   	Node * npx;
};
 

 Node * head = NULL;
 Node * XOR(Node * a,Node *b)
 {


 	return (Node *) ((uintptr_t)(a)^(uintptr_t)(b));
 }
 

 void insertB(int data)
 {
   Node * temp = new Node();
   temp -> data = data;
   temp -> npx = XOR(NULL,head);
   if(head==NULL)
   	head= temp;
   else
   {
     head->npx = XOR(temp,head->npx);
     head= temp;
    }


 }
 

 void insertE(int data)
 {
   Node * temp = new Node();
   temp -> data = data;
   Node * curr = head;
   Node * prev = NULL;
   Node * next = NULL;

   if(head == NULL)
   {
     head = temp;
     temp -> npx = XOR(NULL,NULL);
   }

   else
   {

   	 while(curr!= NULL)
   	 {

   	 	next = XOR(prev,curr->npx);
   	 	prev = curr;
   	 	curr =next;
   	  }
   	  prev->npx = XOR(prev->npx,temp);
   	  temp->npx = XOR(prev,NULL);
   	  }	
 }
  
void print()
{

  Node * curr = head;
  Node * next;
  Node * prev = NULL;
  while(curr! = NULL)
  {
    cout<<curr->data<<"";
    next = XOR(prev,curr->npx);
    curr =  next;
   }
 }  


 int main()
 {
   head = NULL;
   int choice ;
   cout<<"enter choice :"<<endl;
   cout<<"1. INSERT AT BEGINING \n 2.INSERT AT THE END "<<endl;
   cin>>choice;
   cout<<"enter the number of nodes:"<<endl;
   int n;
   cin>>n;
   cout<<"enter the values : "<<endl;
   while(n--)
   {
      int ele;
      cin>>ele;
      if(choice == 1)
      	insertB(ele);
      else
      	insertE(ele);
    }
    
    cout<<"the output is "<<endl;
    print();
    return 0;


  }



 




 