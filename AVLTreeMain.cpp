#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class AVLTree
{
	public:
		Node* root;
		
//		Constructor
		AVLTree()
		{
			root=NULL;
		}
		
		//function to calculate max
		int max(int a, int b)
		{
			if(a>b)
			{
				return a;
			}
			else
			{
				return b;
			}
		}
		
		//function to calculate height of tree
		int height(Node* temp)
		{
			if(root==NULL)
			{
				//no nodes
				return -1;
			}
			else if(temp->left==NULL && temp->right==NULL)
			{
				//node with no child i.e., leaf node
				return 0;
			}
			return (1+max(height(temp->left),height(temp->right)));
		}
		
		//left rotation LL
		Node* LLRot(Node* p)
		{
			Node* temp=p->left;
			p->left=temp->right;
			temp->right=p;
			return temp;
		}
		
		//right rotation RR
		Node* RRRot(Node* p)
		{
			Node* temp=p->right;
			p->right=temp->left;
			temp->left=p;
			return temp;
		}
		
		//LR rotation
		Node* LRRot(Node* p)
		{
			Node* temp=RRRot(p->left);
			p=LLRot(p);
			return p;
		}
		
		//RL rotation
		Node* RLRot(Node* p)
		{
			Node* temp=LLRot(p->right);
			p=RRRot(p);
			return p;
		}
		
		Node* insert(int key,Node* temp)
		{
			if(temp==NULL)
			{
				Node* nn=new Node;
				nn->data=key;
				nn->left=nn->right=NULL;
				temp=nn;
				return temp;
			}
			//insertion to left:
			else if(temp->data > key)
			{
				temp->left=insert(key,temp->left);
				if(height(temp->left)-height(temp->right)==2)
				{
					if(temp->left->data > key)
					{
						temp=LLRot(temp);
					}
					else
					{
						temp=LRRot(temp);
					}
				}
				return temp;
			}
			
			//insertion to right:
			else if(temp->data < key)
			{
				temp->right=insert(key,temp->right);
				if(height(temp->left)-height(temp->right)==-2)
				{
					if(temp->right->data > key)
					{
						temp=RLRot(temp);
					}
					else
					{
						temp=RRRot(temp);
					}
				}
				return temp;
			}
		}
		
		//inorder traversal
		void inorder(Node* temp)
		{
			if(temp!=NULL)
			{
				inorder(temp->left);
				cout<<temp->data<<"  ";
				inorder(temp->right);
			}
		}

		void preorder(Node* temp)
		{
			cout<<"hii";
			if(temp!=NULL)
			{
				cout<<temp->data<<"  ";
				preorder(temp->left);
				preorder(temp->right);
			}
		}
};

int main()
{
	AVLTree a;
    
    a.root=a.insert(1,a.root);
    a.root= a.insert(2,a.root);
    a.root=a.insert(4,a.root);
    a.root=a.insert(33,a.root);
    a.root=a.insert(9,a.root);
    cout<<"Inorder: ";
    a.inorder(a.root);
    cout<<"\nPreorder: ";
    a.preorder(a.root);
	return 0;
}
