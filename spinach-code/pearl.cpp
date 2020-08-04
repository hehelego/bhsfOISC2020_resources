#include <bits/stdc++.h>
int read(){
	int x=0;char c;
	do{c=getchar();}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x;
}
const int mod=998244353;
const int N=1000;
int qpow(int a,int p=mod-2){
	int r=1;
	while(p){
		if(p&1) r=1LL*r*a%mod;
		a=1LL*a*a%mod; p>>=1;
	} return r;
}
int D,n,m,fac[N],ifac[N];
int ans=0;
void dfs(int step,int sum,int qwq,int now){
	if(step>D){
		if(now>=m) ans=(ans+1LL*fac[n]*qwq%mod)%mod;
		return ;
	}
	if(step<D){
		for(int i=0;i<=n&&i+sum<=n;i++){
			dfs(
				step+1,
				sum+i,
				1LL*qwq*ifac[i]%mod,
				now+i/2
			);
		}
	}else{
		int i=n-sum;
		dfs(
				step+1,
				sum+i,
				1LL*qwq*ifac[i]%mod,
				now+i/2
		   );
	}
		
}

int main(){
	D=read();n=read();m=read();

	fac[0]=1;ifac[0]=1;
	for(int i=1;i<N;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=qpow(fac[i]);
	}
	dfs(1,0,1,0);
	std::cout<<ans<<std::endl;
	return 0;
}
