template <typename T>
class SegmentTree{
private:
  T n, DEAD;
  vector<T> st;
  function<T(T, T)>comb;
public:
  SegmentTree(int n, function<T(T, T)>comb, int DEAD=0){
      this->n=n, this->comb=comb, this->DEAD=DEAD;
      st.resize(n<<2);
      for(int i=0;i<(n<<2);i++)this->st[i]=DEAD;  
  }
  void build(vector<int>& a, int lx, int rx, int x){
      if(lx==rx){st[x]=a[lx]; return;}
      int mid=(lx+rx)>>1;
      build(a, lx, mid, (x<<1)+1);
      build(a, mid+1, rx, (x<<1)+2);
      st[x]=this->comb(st[(x<<1)+1], st[(x<<1)+2]);
  }
  void build(vector<int>& a){build(a, 0, n-1, 0);}
  T query(int l, int r, int lx, int rx, int x){
      if(rx<l or r<lx)return DEAD;
      if(l<=lx and rx<=r)return st[x];
      int mid=(lx+rx)>>1;
      T q1=query(l, r, lx, mid, (x<<1)+1); 
      T q2=query(l, r, mid+1, rx, (x<<1)+2); 
      return this->comb(q1, q2);
  }
  T query(int l, int r){return query(l, r, 0, n-1, 0);}
  void update(int idx, T val, int lx, int rx, int x){
      if(lx==rx){st[x]=val;   return;}
      int mid=(lx+rx)/2;
      if(idx<=mid)update(idx, val, lx, mid, (x<<1)+1);
      else update(idx, val, mid+1, rx, (x<<1)+2);
      st[x]=this->comb(st[(x<<1)+1], st[(x<<1)+2]);
  }
  void update(int idx, T val){update(idx, val, 0, n-1, 0);}
};
