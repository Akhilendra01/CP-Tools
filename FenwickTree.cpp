template <typename T>
class FenwickTree{
private:
	int n;
	vector<T> bit;
public:
	FenwickTree(vector<T> a){
		n=a.size();
		bit.resize(n+1);
		for(int i=1;i<=n;i++)this->update(i, a[i]);
	}

	void update(int idx, int val){
		for(;idx<=n;idx+=(idx&(-idx)))bit[idx]+=val;
	}

	T query(int idx){
		T res=0;
		for(;idx>0;idx-=(idx&(-idx)))res+=bit[idx];
		return res;
	}

	T query(int l, int r){
		return query(r)-query(l-1);
	}
};
