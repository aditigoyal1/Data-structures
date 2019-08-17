#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> > adjlist;
	
	public:
		void addedge(T u,T v,bool bdir)
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
		
		bool isCyclicBFS(T src)
		{
			queue<T> q;
			map<T,bool> visited;
			map<T,T> parent;
			
			q.push(src);
		
				visited[src]=true;
				parent[src]=src;
			
			
			
			//start algorithm
			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				
				
				for(auto i:adjlist[node])
				{
					
					if(parent[node]!=i &&visited[i]==true)
					{
						return true;
					}
					else if(!visited[i])
					{
						visited[i]=true;
						parent[i]=node;
						q.push(i);
					}
				}
			}
			
			return false;
			
			
		}
		
		
};

int main()
{
	Graph<int> g;
	int edges;
	cin>>edges;
	int u,v;
		bool s;
	for(int i=0;i<edges;i++)
	{
		
		cin>>u>>v;
		
		g.addedge(u,v,true);
		
	}
	
	
	if(g.isCyclicBFS(1))
	{
		cout<<"Cyclic graph";
	}
	else
	{
		cout<<"Non-Cyclic graph";
	}
	
	return 0;
	
	
}


/*
test cases
4
1 2
1 4
4 3
2 3 

3
1 2
1 4
2 3
*/

