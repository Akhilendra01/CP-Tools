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

	void bfs(int source){
		bool *visited=new bool[V]{0};
		queue<int> q;
		q.push(source);
		visited[source]=true;
		while(!q.empty()){
			int top=q.front();
			cout<<top<<endl;
			q.pop();
			for(auto nbr: l[top]){
				if(visited[nbr]==false){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
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
    g.bfs(1);
	return 0;
}