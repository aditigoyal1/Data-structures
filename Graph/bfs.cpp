#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> > adjlist;
	
	public:
		void addedge(T u,T v,bool bdir=true)
		{
			adjlist[u].push_back(v);
			
			if(bdir)
			{
				adjlist[v].push_back(u);
			}
			
		}
		
		void print()
		{
			for(auto i:adjlist)
			{
				cout<<i.first<<"->";
				for(auto entry :i.second)
				{
					cout<<entry<<",";
				}
				cout<<endl;
			}
		}
		
		void bfs( T src)
		{
			queue<T> q;
			map<T,bool> visited;
			q.push(src);
			visited[src]=true;
			while(!q.empty())
			{
				T node=q.front();
				cout<<node<<",";
				q.pop();
				for(int neighbour:adjlist[node])
				{
					if(!visited[neighbour])
					{
						q.push(neighbour);
						visited[neighbour]=true;
						
					}
				}
			}
			cout<<endl;
		}
		
		void bfssortestpath(T src)
		{
			queue<T> q;
			map<T,int> dist;
			map<T, T> parent;
			for(auto i:adjlist)
			{
				dist[i.first]=INT_MAX;
				
			}
			
			q.push(src);
			parent[src]=src;
			dist[src]=0;
			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				cout<<node<<" ";
				for(T neighbour:adjlist[node])
				{
					if(dist[neighbour]==INT_MAX)
					{
						q.push(neighbour);
						dist[neighbour]=dist[node]+1;
						parent[neighbour]=node;
					}
				}
			}
			
			for(auto i:adjlist)
			{
				T node=i.first;
				cout<<"Distance of "<<node<<" from "<<src<<" is "<<dist[node]<<endl;
				cout<<"Parent of "<<node<<" is "<<parent[node]<<endl;
			}
		}
	
};

int main()
{
	Graph<int> g;
	int edges;
	cin>>edges;
	for(int i=0;i<edges;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addedge(u,v);
		
	}
	
	g.print();
	g.bfs(0);
	g.bfssortestpath(0);
	
	return 0;
	
	
}


/*
test cases
7
0 1
1 2
0 4
2 4
2 3
3 5
3 4

*/

