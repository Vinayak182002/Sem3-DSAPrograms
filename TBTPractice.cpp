#include<iostream>
using namespace std;

struct node
{
	int data;
	node *left,*right;
	bool lth,rth;
};

class TBT
{
	node* root;
	public:
		TBT()
		{
			root=new node;
			root->left=root->right=root;
			root->data=65536;
			root->lth=true;
		}
		
		void insertnode()
		{
			int key;
			cout<<"\nEnter element you want to insert:";
			cin>>key;
			node* p=root;
			for(;;)
			{
				if(p->data<key)
				{
					if(p->rth==true)
					{
						break;
					}
					p=p->right;
				}
				else if(p->data>key)
				{
					if(p->lth==true)
					{
						break;
					}
					p=p->left;
				}
				else
				{
					//already inserted!
					return;
				}
			}
			
			node* nn=new node;
			nn->data=key;
			nn->lth=nn->rth=true;
			
			if(p->data<key)
			{
				nn->right=p->right;
				p->rth=false;
				nn->left=p;
				p->right=nn;
			}
			else
			{
				nn->left=p->left;
				p->lth=false;
				nn->right=p;
				p->left=nn;
			}
		}
		
		void print()
		{
			node* tmp=root;
			node* p;
			for(;;)
			{
				p=tmp;
				tmp=tmp->right;
				if(p->rth==false)
				{
					while(tmp->lth==false)
					{
						tmp=tmp->left;
					}
				}
				if(tmp==root)
				{
					break;
				}
				cout<<tmp->data<<" ";
			}
		}
//		void print()
//		{
//			node* tmp=root->left;
//			if(tmp==NULL)
//			{
//				cout<<"\nTree is empty!";
//			}
//			while(tmp->lth==false)
//			{
//				tmp=tmp->left;
//			}
//			while(tmp!=NULL)
//			{
//				cout<<tmp->data<<"  ";
//				tmp=inordersuc(tmp);
//			}
//		}
//		
//		node* inordersuc(node* ptr)
//		{
//			if(ptr->rth==true)
//			{
//				return ptr->right;
//			}
//			ptr=ptr->right;
//			while(ptr->lth==false)
//			{
//				ptr=ptr->left;
//			}
//			return ptr;
//		}
};

int main()
{
	TBT tbt;
	int ch,doch;
	do
	{
		cout<<"\n1.Insert\n2.Print";
		cout<<"\n:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				tbt.insertnode();
				break;
			
			case 2:
				tbt.print();
				break;
		}
		cout<<"\nContinue?-->";
		cin>>doch;	
	}while(doch==1);
	
	return 0;

}
