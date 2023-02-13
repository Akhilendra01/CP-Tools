#define mod ((int)1e9+7)

class mint{
private:
	int n;
	mint(){this->n=0;}
	mint(int n){this->n=n%mod;}
	int get(){return n;}
	int power(int a, int b){
		int r=1;
		while(b){if(b&1)r=(r*a)%mod;a=(a*a)%mod; b/=2;}
		return r;
	}
	int inv(int a){return power(a, mod-2)%mod;}
public:
	mint operator+(mint m){return (n+m.get())%mod;}
	mint operator-(mint m){return (n-m.get()+mod)%mod;}
	mint operator*(mint m){return (n*m.get())%mod;}
	mint operator/(mint m){return (n*inv(m.get()))%mod;}
};
