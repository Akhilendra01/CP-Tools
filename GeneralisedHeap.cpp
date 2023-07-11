template <typename T>
class Heap{
private:
	T *a;
	int idx, maxSize;
public:
	bool (*comp)(T, T);
	Heap(T* arr, int curSize, int maxSize, bool (*comp)(T, T)){
		a=(T*)malloc(sizeof(T)*maxSize);
		for(int i=0;i<curSize;i++)a[i]=arr[i];
		this->idx=curSize-1;
		this->maxSize=maxSize;
		this->comp=comp;
		this.build();
	}
	Heap(int maxSize, bool (*comp)(T, T)){
		a=(T*)malloc(sizeof(T)*maxSize);
		this->idx=-1;
		this->maxSize=maxSize;
		this->comp=comp;
	}
private:
	void heapify(int i){
		int large=i;
		int l=(i<<1)+1, r=(i<<1)+2;
		if(l<=idx and !comp(a[large], a[l]))large=l;
		if(r<=idx and !comp(a[large], a[r]))large=r;
		if(large!=i){swap(a[large], a[i]);	heapify(large);}
	}
	void reheapify(int x){
		if(x==0)return;
		int par=(x-1)>>1;
		if(!comp(a[par], a[x])){swap(a[par], a[x]);	reheapify(par);}
	}
	void buildHeap(){for(int i=(idx-1)>>1;i>=0;i--)heapify(i);}	
public:
	void push(T x){
		idx++;	a[idx]=x;
		reheapify(idx);
	}
	void pop(){
		swap(a[0], a[idx]);
		idx--;	heapify(0);
	}
	int size(){return idx+1;}
	bool empty(){return idx==-1;}
	T top(){return a[0];}
};
