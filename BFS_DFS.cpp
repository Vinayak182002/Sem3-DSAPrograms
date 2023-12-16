/*
 *	======================================
 * 		Program Name: BFS_DFS.cpp
 *  	Created on: December 15, 2022
 *      Author: Vinayak Shete
 *  ======================================
 */
 
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Graph
{
    int adjacency[10][10];
    int v;
    int visited_array[10];

	public:
		//using constructor for storing intitial values in the matrix
    	Graph(int n)
    	{
       	 	v=n;
        	for(int i=0; i<v; i++)
        	{
            	for(int j=0; j<v; j++)
            	{
                	adjacency[i][j]=0;
            	}
        	}
        	for(int i=0; i<v; i++)
        	{
            	visited_array[i]=0;
        	}
    	}

		//function for adding an edge
    	void add_edge(int v1, int v2)
    	{
        	adjacency[v1][v2]=1;
        	adjacency[v2][v1]=1;
    	}

		//function for displaying the graph in the form of adjacency matrix
    	void display()
    	{
        	cout<<"\n======\nEdges in the graoh are: \n";
        	for(int i=0; i<v; i++)
        	{
            	for(int j=0; j<v; j++)
            	{
                	if(adjacency[i][j]==1)
                	{
                    	cout<<"("<<i<<","<<j<<")"<<" ";
                	}
            	}
        	}
    	}
    
    	//BFS Traversal of a graph
    	void bfs(int val)
    	{
        	queue<int> q;
        	int visited[v]={0};
        	q.push(val);
        	visited[val]=1;
        	while(!q.empty())
       		{
            	int temp=q.front(); 
            	q.pop();
            	cout<<temp<<" ";
            	for(int i=0; i<v; i++)
            	{
                	if(adjacency[temp][i]==1 && visited[i]==0)  
                	{
                    	q.push(i);
                    	visited[i]=1;
                	}
            	}
        	}
    	}
    
    	//DFS Traversal of a graph
    	void dfs(int val)
    	{
        	stack <int> s;
       	 	for(int i=0; i<v; i++)
        	{
            	visited_array[i]=0;
        	}
        	s.push(val);
        	while(!s.empty())
        	{
            	int v1=s.top();
            	s.pop();
            	if(visited_array[v1]==0)
            	{
                	cout<<v1<<" ";
                	visited_array[v1]=1;
            	}
        
            	for(int i=0; i<v; i++)
            	{
                	if(adjacency[v1][i]==1 && visited_array[i]==0)
                	s.push(i);
            	}
        	}
    	}
};

int main()
{
	int vert,ch,doch,src,dest;
	cout<<"\n=======WELCOME======";
	cout<<"\nHow many vertices you want in the GRAPH?-->";
	cin>>vert;
    Graph g(vert);
    cout<<"\nThe graph with vertices 0 to "<<vert-1<<" has been created!\n====";
    do
    {
    	cout<<"\n1.Add Edge\t\t2.Display\n3.BFS Traversal\t\t4.DFS Traversal\t\t5.EXIT";
    	cout<<"\nEnter your proper choice:";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1:
    			cout<<"\nEnter the source:";
    			cin>>src;
    			cout<<"\nEnter the destination:";
    			cin>>dest;
    			g.add_edge(src,dest);
    			break;
    		
    		case 2:
    			g.display();
    			break;
    		
    		case 3:
    			cout<<"\nBFS Traversal of the graph is: ";
    			g.bfs(1);
    			break;
    		
    		case 4:
    			cout<<"\nDFS Traversal of the graph is: ";
    			g.dfs(1);
    			break;
    		
    		case 5:
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
		cout<<"\n================THANK YOU!================";
    return 0;
}
