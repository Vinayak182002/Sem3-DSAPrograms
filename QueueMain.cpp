/*
 *	======================================
 * 		Program Name: QueueMain.cpp
 *  	Created on: November 23, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

class Queue
{
	struct Node *front= NULL;
	struct Node	*rear = NULL; 
	public:
		void insert(int dt)
		{
			struct Node *nn = new Node();
			nn->data=dt;
			nn->next=NULL;
			
			if(front==NULL && rear==NULL)
			{
					front=nn;
					rear=nn;
			}
			else
			{
					rear->next=nn;
					rear=nn;
			}
		}
		
		void dequeue()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty!Deletion Operation failed!";	
			}	
			else
			{
				struct Node *tmp=front;
				front=front->next;
				cout<<"\nAn element "<<tmp->data<<" which was at FRONT has been Deleted!";
			}
		}
		
		void display()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty!Display Operation failed!";
			}
			else
			{
				struct Node *tmp=front;
				cout<<"\nThe elements in the Queue are: \n";
				while(tmp!=NULL)
				{
					cout<<tmp->data<<"|->";
					tmp=tmp->next;
				}
				cout<<"NULL\n";
			}
		}
};

int main() 
{
	Queue q;
	int n,ch,doch;
	cout<<"\n=====WELCOME========";
	cout<<"\n========= Queue Operations using Linkedlist =========";
	do
	{
		cout<<"\n===========";
		cout<<"\n1.Add Element into Queue(Enqueue)\n2.Delete Element from Queue(Dequeue)\n3.Display elements in the Queue\n4.Exit";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter any number to insert in Queue: ";
				cin>>n;
				q.insert(n);
				break;
				
			case 2:
				q.dequeue();
				break;
				
			case 3:
				q.display();
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
