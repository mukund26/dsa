/*
	Implementation of graph .... 
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

class Graph{
	int v;
	vi *adj;

public:

	Graph(int size){
		v=size;
		adj = new vi[v];
	}

	void addEdge(int u,int v){
		adj[u].push_back(v);
	}

	void print();

	void topologicalsortuntil(int source,bool visited[],stack<int> &s);

	void topologicalsort();

};

void Graph :: print(){
	for(int i=0;i<v;i++){
		cout<<"Adjacent verteces to"<<i+1<<endl;
		for(auto x:adj[i]){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

void Graph :: topologicalsortuntil(int source,bool visited[],stack<int> &s){
	visited[source]=true;

	for(auto x:adj[source]){
		if(!visited[x]){
			topologicalsortuntil(x,visited,s);
		}
	}

	s.push(source);
}

void Graph :: topologicalsort(){
	bool visited[v];
	memset(visited,false,sizeof(visited));

	stack<int> s;
	for(int i=0;i<v;i++){
		if(!visited[i]){
			topologicalsortuntil(i,visited,s);
		}
	}

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(){
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
	//g.bfs(2); cout<<endl;
	g.topologicalsort(); cout<<endl;
	return 0;
}
