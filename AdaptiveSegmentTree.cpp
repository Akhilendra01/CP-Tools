/*
	author: akhilendra11
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

struct SegmentTree{
private:
	int *st, n, DEAD;
	int (*comb)(int, int);
public:
	SegmentTree(int n, int (*comb)(int, int), int DEAD=0){
		this->n=n;
		this->comb=comb;
		this->DEAD=DEAD;
		st=(int*)malloc(sizeof(int)*(this->n)<<2);
		for(int i=0;i<(n<<2);i++)this->st[i]=DEAD;	
	}
	void build(int *a, int lx, int rx, int x){
		if(lx==rx){st[x]=a[lx]; return;}
		int mid=(lx+rx)>>1;
		build(a, lx, mid, (x<<1)+1);
		build(a, mid+1, rx, (x<<1)+2);
		st[x]=comb(st[(x<<1)+1], st[(x<<1)+2]);
	}
	void build(int *a){
		build(a, 0, n-1, 0);
	}
	int query(int l, int r, int lx, int rx, int x){
		if(rx<l or r<lx)return DEAD;
		if(l<=lx and rx<=r)return st[x];
		int mid=(lx+rx)>>1;
		int q1=query(l, r, lx, mid, (x<<1)+1); 
		int q2=query(l, r, mid+1, rx, (x<<1)+2); 
		return comb(q1, q2);
	}
	int query(int l, int r){
		return query(l, r, 0, n-1, 0);
	}
	void update(int idx, int val, int lx, int rx, int x){
		if(lx==rx){st[x]=val;	return;}
		int mid=(lx+rx)>>1;
		if(idx<=mid)update(idx, val, lx, mid, (x<<1)+1);
		else update(idx, val, mid+1, rx, (x<<1)+2);
		st[x]=comb((x<<1)+1, (x<<1)+2);
	}
	void update(int idx, int val){
		update(idx, val, 0, n-1, 0);
	}
};

int comb(int a, int b){return max(a, b);}

int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	SegmentTree tree(n, comb, 0);	tree.build(a);
	cout<<tree.query(1, 5)<<"\n";
	tree.update(2, 0);	cout<<tree.query(1, 5);

	return 0;
}
