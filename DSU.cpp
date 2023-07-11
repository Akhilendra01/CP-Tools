class DSU{
private:
	int n, *par, *rank;
public:
	DSU(int n){
		this->n=n;
		par=(int*)malloc(sizeof(int)*(n+1));
		rank=(int*)malloc(sizeof(int)*(n+1));
		memset(rank, 0, sizeof(rank));
		iota(par, par+n+1, 0);
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void merge(int a, int b){
		a=find(a), b=find(b);
		if(a!=b){
			if(rank[a]<rank[b])swap(a, b);
			par[b]=a;
			if(rank[a]==rank[b])rank[a]++;
		}
	}
};
