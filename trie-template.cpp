template <int N, char B>
class TrieNode{
private:
	TrieNode<N, B>* link[N];
	bool end;
public:
	TrieNode(){
		for(int i=0;i<N;i++)link[i]=nullptr;
		end=false;
	}
	bool containsKey(char c){return link[c-B]!=nullptr;}
	
	TrieNode<N, B>* get(char c){return link[c-B];}
	
	void put(char c, TrieNode<N, B>* node){link[c-B]=node;}

	void setEnd(){end=true;}

	bool isEnd(){ return end; }
};

template <int N, char B>
class Trie{
private:
	TrieNode<N, B>* root;
public:
	Trie(){
		root=new TrieNode<N, B>();
	}

	void insert(string& s){
		int n=s.size();
		TrieNode<N, B>* node=root;
		for(int i=0;i<n;i++){
			if(!node->containsKey(s[i])){
				node->put(s[i], new TrieNode<N, B>());
			}
			node=node->get(s[i]);
		}
		node->setEnd();
	}
};
