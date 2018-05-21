#include <bits/stdc++.h>
#include "DijSet.h"
using namespace std;

typedef  pair<int, int> iPair;

class Grafo{

public:
	int n, m;
	vector< pair<int, iPair >> edges;

	Grafo(int n, int m){
		this->n = n;
		this->m = m;
	}

	void add_edge(int u, int v, int w){
		edges.push_back({w,{u,v}});
	}

	int kruskal(){
		int w_total = 0;
		
		sort(edges.begin(), edges.end());
	
		DijSet ds(n);
		
		for (int i=0;i<edges.size();i++){
			
			int u = edges[i].second.first;
			int v = edges[i].second.second;
			int set_u = ds.find(u);
			int set_v = ds.find(v);
			
			if (set_u != set_v){
				cout << u << " - " << v << endl;
				w_total += edges[i].first;
				ds.union_find(u, v);
			}
		}
		return w_total;
	}
};

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n,m,u,v,w;
	cin>>n>>m;
	Grafo g(n, m);
	for(int i=0;i<m;i++){
	    cin>>u>>v>>w;
	    g.add_edge(u,v,w);
	}
	cout << "Edges of MST "<<endl;
	int peso = g.kruskal();

	cout << endl <<"Weight of MST is " << peso;
	return 0;
}

	/*
	Homework:
	-> Rebuild the graph
	-> Build the table (w,edge,selected)
	-> Applied the algorithm
	-> Check your answers with the output of the program
	-> Create a function in order to load the edges and weights from a file (PC2)
	-> Recreate the class in order to use classes (for intance: points) , use templates.
	-> 
	*/
