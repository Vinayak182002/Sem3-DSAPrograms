#include<iostream>
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
		void push(int dt)
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
		
		void pop()
		{
			if(front==NULL)
			{
				cout<<"\nQueue is empty!Deletion Operation failed!";	
			}	
			else
			{
				struct Node *tmp=front;
				front=front->next;
//				cout<<"\nAn element "<<tmp->data<<" which was at FRONT has been Deleted!";
			}
		}
		
		Node* getfront()
		{
			return front;
		}	
		
		bool empty()
		{
			if(front==NULL)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
};

class BFS
{
	int adj[10][10];
	int v;
	int visited_array[10];
	public:
		BFS(int n)
		{
			v=n;
			for(int i=0;i<v;i++)
			{
				for(int j=0;j<n;j++)
				{
					adj[i][j]=0;		
				}
			}	
			
			for(int i=0;i<v;i++)
			{
				visited_array[i]=0;
			}
		}	
		
		void add_edge(int src,int dest)
		{
			adj[src][dest]=1;
			adj[dest][src]=1;
		}
		
		void bfs(int val)
		{
			int visited[v]={0};
			Queue q;
			q.push(val);
//			Node* t=q.getfront();
			Node* t;
			while(q.empty()==false)
			{
				t=q.getfront();
				cout<<t->data;
				q.pop();
				
				for(int i=0;i<v;i++)
				{
					if(adj[t->data][i]==1 && visited[i]==0)
					{
						q.push(i);
						visited[i]=1;
					}
				}
			}
		}
};

int main()
{
	int n;
	cout<<"\nEnter no of vertices:";
	cin>>n;
	BFS b(n);
	b.add_edge(0,1);
	b.add_edge(0,3);
	b.add_edge(1,2);
	b.add_edge(1,5);
	b.add_edge(1,3);
	b.add_edge(1,6);
	b.add_edge(2,3);
	b.add_edge(2,5);
	b.add_edge(3,4);
	b.add_edge(4,6);
	
	cout<<"\nBFS:";
	b.bfs(0);
	
	return 0;
}
