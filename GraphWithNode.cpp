#include<bits/stdc++.h>
using namespace std;

#define int long long int


class Node{

public:
	string name;
	list<string> nbrs;

	Node(string name){
		this->name=name;
	}

};

class Graph{
public:
	unordered_map<string, Node*> m;

	Graph(vector<string> cities){
		for(auto city: cities){
			m[city]=new Node(city);
		}
	}

	void addEdge(string s1, string s2, bool undir=false){
		m[s1]->nbrs.push_back(s2);
		if(undir){
			m[s2]->nbrs.push_back(s1); 
		}
	}

	void printAdjList(){
		for(auto city: m){
			cout<<city.first<<"-->";
			for(auto n: city.second->nbrs){
				cout<<n<<" ";
			}
			cout<<endl;
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

	vector<string> cities={"Delhi", "London", "Paris", "New York"};
	Graph g(cities);
	g.addEdge("Delhi", "London");
	g.addEdge("New York", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");
	g.printAdjList();
	
	return 0;
}