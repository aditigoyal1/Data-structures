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
		
		void topologicalsort()
		{
			queue<T> q;
			map<T,bool> visited;
			map<T,int> indegree;
			
			for(auto i:adjlist)
			{
				T node=i.first;
				visited[node]=false;
				indegree[node]=0;
			}
			
			for(auto i:adjlist)
			{
				for(auto j:i.second)
				{
					indegree[j]++;
				}
			}
			//find all node with 0 indegree
			for(auto i:adjlist)
			{
				if(indegree[i.first]==0)
				{
					q.push(i.first);
				}
			}
			//start algorithm
			while(!q.empty())
			{
				T node=q.front();
				q.pop();
				cout<<node<<"->";
				
				for(auto i:adjlist[node])
				{
					indegree[i]--;
					if(indegree[i]==0)
					{
						q.push(i);
					}
				}
			}
			
			
		}
		
		
};

int main()
{
	Graph<string> g;
	int edges;
	cin>>edges;
	string u,v;
		bool s;
	for(int i=0;i<edges;i++)
	{
		
		cin>>u>>v;
		
		g.addedge(u,v,false);
		
	}
	
	
	g.topologicalsort();
	
	return 0;
	
	
}


/*
test cases
12
eng ppl 
maths ppl 
ppl html 
ppl python 
ppl java 
ppl js 
python webd 
html css 
css js 
js webd 
java webd 
python webd 

*/

