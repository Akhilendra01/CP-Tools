int power(int a, int b){
	int r=1;
	while(b){
		if(b&1)r=(r*a)%mod; a=(a*a)%mod; b/=2;
	}
	return r;
}
int inv(int x){return power(x, mod-2);}
class Z {
public:
	int n, M;
  Z() : n(0), M(mod) {}Z(int n) : n(n), M(mod) {}
  void operator=(int n) { this->n = n; }
  friend std::ostream& operator<<(std::ostream& os, const Z& z) {os << z.n; return os;}
  friend std::istream& operator>>(std::istream& is, Z& z) {is >> z.n; return is;}
  Z operator+(const Z& b) const { return Z((n + b.n)%M); }
  Z operator-(const Z& b) const { return Z((n - b.n + M)%M); }
  Z operator*(const Z& b) const { return Z((n*b.n)%M); }
  Z operator/(const Z& b) const { return Z((n*inv(b.n))%M); }
  Z operator%(const Z& b) const { return Z(n%(b.n)); }
  Z& operator+=(const Z& b) {n = (n + b.n) % M; return *this; }
  Z& operator-=(const Z& b) {n = (n - b.n + M) % M; return *this; }
  Z& operator*=(const Z& b) {n = (n * b.n)% M; return *this; }
  Z& operator/=(const Z& b) {n = (n * inv(b.n))% M; return *this; }
  Z& operator%=(const Z& b) {n = (n % b.n); return *this; }
  Z& operator++(){n=(n+1)%M; return *this;} 
  Z operator++(int32_t) {Z temp(*this); ++(*this); return temp; }
  Z& operator--(){n=(n-1+M)%M; return *this;} 
  Z operator--(int32_t) {Z temp(*this); --(*this); return temp; }
  bool operator==(const Z&b){return n==b.n;}
  bool operator!=(const Z&b){return n!=b.n;}
};
