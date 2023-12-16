/*
 *	======================================
 * 		Program Name: StackMain.cpp
 *  	Created on: November 23, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

class Stack
{
	public:
		struct Node *top;
	
		void push(int dt)
		{
			struct Node *nn = (struct Node*) malloc(sizeof(struct Node));
			nn->data=dt;
			nn->next= top;
			top=nn;
		}
	
		void pop()
		{
			if(top==NULL)
			{
				cout<<"\nStack underflow!POP operation failed!";
			}
			else
			{
				Node *tmp=top;
				int dt = top->data;
				top=top->next;
				free(tmp);
				cout<<"\nAn element "<<dt<<" which was at TOP has been Deleted!";
			}
		}
	
		void display()
		{
			if(top==NULL)
			{
				cout<<"\nStack is empty!Display Operation failed!";
			}
			else
			{
				Node *tmp=top;
				cout<<"\nStack elements are: ";
				while(tmp!=NULL)
				{
					cout<<tmp->data<<" ";
					tmp=tmp->next;
				}
			}
		}
};

int main() 
{
	Stack st;
	int val,ch,doch;
	cout<<"\n=====WELCOME========";
	cout<<"\n========= Stack operations ==========";
	do
	{
		cout<<"\n===========";
		cout<<"\n1.Add element into Stack(PUSH)\n2.Delete element from Stack(POP)\n3.Display elements in the Stack\n4.EXIT";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter any number to push: ";
		 		cin>>val;
				st.push(val);
				break;
				
			case 2:
				st.pop();
				break;	
					
			case 3:
				st.display();
				break;
			
			case 4:
				goto exit;
				break;
			
			default:
				cout<<"\nPlease enter correct choice!";
				break;
		}	
		cout<<"\n=======\nDo you want to continue?[1 for YES || 0 for No]-->";
		cin>>doch;
	}while(doch==1);
	exit:
		cout<<"\n=====THANK YOU!=======";
	return 0;
}
