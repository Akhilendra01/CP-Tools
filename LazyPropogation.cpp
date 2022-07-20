#include<bits/stdc++.h>
using namespace std;

#define int long long int

struct SegmentTree{
	vector<int> st;
	vector<int> lazy;
	int n;

	void init(int _n){
		this->n=_n;
		st.resize(4*n, 0);
		lazy.resize(4*n, 0);
	}

	void build(int start, int end, int node, vector<int>& v){
		if(start==end){
			st[node]=v[start];
			return;
		}
		int mid=(start+end)/2;
		build(start, mid, 2*node+1, v);
		build(mid+1, end, 2*node+2, v);
		st[node]=st[2*node+1]+st[2*node+2];
		return;
	}
	void build(vector<int> v){
		build(0, n-1, 0, v);
	}

	int query(int start, int end, int l, int r, int node){
		if(start>r || end<l)return 0;

		if(lazy[node]!=0){
			st[node]=lazy[node]*(end-start+1);
			if(start!=end){
				lazy[2*node+1]+=lazy[node];
				lazy[2*node+2]+=lazy[node];
			}
			lazy[node]=0;
		}

		if(start>=l && end <=r){
			return st[node];
		}
		int mid=(start+end)/2;
		int q1=query(start, mid, l, r, 2*node+1);
		int q2=query(mid+1, end, l, r, 2*node+2);
		return q1+q2;
	}

	int query(int l, int r){
		return query(0, n-1, l, r, 0);
	}


	void update(int start, int end, int idx, int val, int node){
		if(start==end){
			st[node]=val;
			return;
		}
		int mid=(start+end)/2;
		if(idx<=mid){
			update(start, mid, idx, val, 2*node+1);
		}
		else{
			update(mid+1, end, idx, val, 2*node+2);
		}
		st[node]=st[2*node+1]+st[2*node+2];
	}
	void update(int idx, int val){
		update(0, n-1, idx, val, 0);
	}
	void updateRange(int start, int end, int l, int r, int val, int node){
		if(start>r||end<l)return;

		if(lazy[node]!=0){
			st[node]+=lazy[node]*(end-start+1);
			if(start!=end){
				lazy[2*node+1]+=lazy[node];
				lazy[2*node+2]+=lazy[node];
			}
			lazy[node]=0;
		}
		if(start>=l && end<=r){
			st[node]+=val*(end-start+1);
			if(start!=end){
				lazy[2*node+1]+=val;
				lazy[2*node+2]+=val;
			}
			return;
		}

		int mid=(start+end)/2;
		updateRange(start, mid, l, r, val, 2*node+1);
		updateRange(mid+1, end, l, r, val, 2*node+2);
		st[node]=st[2*node+1]+st[2*node+2];

	}
	void updateRange(int l, int r, int val){
		updateRange(0, n-1, l, r, val, 0);
	}
};


int32_t main(){

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
	cout<<tree.query(1,4)<<endl;
	tree.update(1, 3);
	cout<<tree.query(1, 4)<<endl;
	tree.updateRange(1, 4, -1);
	cout<<tree.query(0, 7);
	
	return 0;
}