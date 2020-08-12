#include <bits/stdc++.h>
const int N=4000+10;
typedef unsigned long long Int;
struct Poly{
	Int a[N];
	Int operator[](int x)const{return a[x];}
	Int& operator[](int x){return a[x];}
	Poly(){ memset(a,0,sizeof(a)); }
};
Int n,k,p,m;

Poly operator*(const Poly&a,const Poly&b){
	Poly c;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++)
		c[i+j]=(c[i+j]+a[i]*b[j])%p;
	for(int i=m;i<N;i++) c[i]=0;
	return c;
}
Poly qpow(Poly a,Int b){
	Poly r; r[0]=1;
	while(b){
		if(b&1) r=r*a;
		a=a*a; b>>=1;
	}
	return r;
}
int main(){
	std::cin>>n>>k>>p; m=k+1;

	Poly q; q[0]=1;q[1]=1;
	q=qpow(q,n);

	Int ans=0; for(int i=1;i<=k;i++) ans=ans^(q[i]%p);
	std::cout<<ans<<std::endl;
	return 0;
}

