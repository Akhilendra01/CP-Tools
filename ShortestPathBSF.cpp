#include<bits/stdc++.h>
using namespace std;

#define int long long int

class Graph{
	int V;
	list<int> *l;
public:
	Graph(int v){
		V=v;
		l=new list<int>[V];
	}

	void addEdge(int i, int j, bool undir=true){
		l[i].push_back(j);
		if(undir){
			l[j].push_back(i);
		}
	}

	void bfs(int source, int dest=-1){
		queue<int> q;
		bool *visited = new bool[V]{0};
		int  *dist=new int[V]{0};
		int *parent=new int[V]{-1};
		q.push(source);
		visited[source]=1;
		parent[source]=source;
		dist[source]=0;
		while(!q.empty()){
			int top=q.front();
			q.pop();
			for(auto nbr: l[top]){
				if(!visited[nbr]){
					q.push(nbr);
					parent[nbr]=top;
					dist[nbr]=dist[top]+1;
					visited[nbr]=1;
				}
			}
		}

		for(int i=0;i<V;i++){
			if(i==source)continue;
			cout<<"Distance of 1 from "<<i<<"="<<dist[i]<<endl;
		}

		if(dest!=-1){
			int temp=dest;
			while(temp!=source){
				cout<<temp<<"<--";
				temp=parent[temp];
			}
			cout<<source;
		}
	}
};



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
	g.bfs(1, 6);
	return 0;
}