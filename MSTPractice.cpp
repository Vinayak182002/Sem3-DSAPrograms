#include<iostream>
#define infinity 9999
using namespace std;

class MST
{
	int vertices,edges;
	int adj[10][10];
	int sp[10][10];
	int minCost=0;
	
	public:
		MST(int n)
		{
			vertices=n;
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					adj[i][j]=0;
					sp[i][j]=0;
				}
			}
		}
		
		void add_edge(int src,int dest,int w)
		{
			adj[src][dest]=w;
			adj[dest][src]=w;
		}
		
		void mst()
		{
			int cost[vertices][vertices]={0};
			int distance[vertices]={infinity};
			int visited[vertices]={0};
			int source[vertices]={0};
			int minDist=0;
			
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					if(adj[i][j]==0)
					{
						cost[i][j]=infinity;
					}
					else
					{
						cost[i][j]=adj[i][j];
					}
				}
			}
			
			distance[0]=0;
			visited[0]=1;
			int src_vertex,dest_vertex;
			for(int i=0;i<vertices;i++)
			{
				distance[i]=cost[0][i];
				source[i]=0;
			}
			
			edges=vertices-1;
			while(edges>0)
			{
				minDist=infinity;
				for(int i=0;i<vertices;i++)
				{
					if(visited[i]==0 && distance[i]<minDist)
					{
						minDist=distance[i];
						dest_vertex=i;
					}
				}
				
				src_vertex=source[dest_vertex];
				sp[src_vertex][dest_vertex]=sp[dest_vertex][src_vertex]=distance[dest_vertex];
				visited[dest_vertex]=1;
				minCost+=cost[src_vertex][dest_vertex];
				edges--;
				
				for(int i=0;i<vertices;i++)
				{
					if(visited[i]==0 && cost[dest_vertex][i]<distance[i])
					{
						distance[i]=cost[dest_vertex][i];
						source[i]=dest_vertex;
					}
				}
			}
			cout<<"\nMinimum Cost="<<minCost;
		}
};

int main()
{
	int n;
	cout<<"\nEnter no of vertices:";
	cin>>n;
	MST m(n);
	m.add_edge(0,1,12);
	m.add_edge(0,3,7);
	m.add_edge(1,2,6);
	m.add_edge(1,3,15);
	m.add_edge(2,4,5);
	m.add_edge(3,4,4);
	m.mst();
}
