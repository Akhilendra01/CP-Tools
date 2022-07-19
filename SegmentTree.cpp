#include<bits/stdc++.h>
using namespace std;

#define int long long int


struct SegmentTree{
	vector<int> st;
	int n;
	//INITIALIZATION
	void init(int _n){
		this->n=_n;
		st.resize(4*n, 0);
	}

	//BUILD
	void build(int start, int ending, int node, vector<int> &v){
		if(start==ending){
			st[node]=v[start];
			return; 
		}
		int mid=(start+ending)/2;
		build(start, mid, 2*node+1, v);
		build(mid+1, ending, 2*node+2, v);
		//Operation here is summation segment tree
		st[node]=st[2*node+1]+st[2*node+2];
	}

	void build(vector<int> v){
		build(0, n-1, 0, v);
	}
	//QUERY
	int query(int start, int ending, int l, int r, int node){
		if(start>r||ending<l) return 0;//no overlap

		if(start>=l && ending<=r){
			return st[node];
		}

		int mid=(start+ending)/2;
		int q1=query(start, mid, l, r, 2*node+1);
		int q2=query(mid+1, ending, l, r, 2*node+2);
		return q1+q2;
	}

	int query(int l, int r){
		return query(0, n-1, l, r, 0);
	}

	//UPDATE
	void update(int start, int ending, int node, int idx, int val){
		if(start==ending){
			st[node]=val;
			return;
		}
		int mid=(start+ending)/2;
		if(idx<=mid){
			update(start, mid, 2*node+1, idx, val);
		}
		else{
			update(mid+1, ending, 2*node+2, idx, val);
		}
		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}

	void update(int idx, int val){
		update(0, n-1, 0, idx, val);
	}

}tree;


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector<int> v={1, 2, 3, 4, 5, 6, 7, 8};
	
	SegmentTree tree;
	tree.init(v.size());
	tree.build(v);
	cout<< tree.query(2, 5)<<endl;
	tree.update(4, 10);
	cout<< tree.query(2, 5);
	return 0;
}
