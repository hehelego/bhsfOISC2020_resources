#include <bits/stdc++.h>
typedef long long Int;
const Int INF=Int(1e15);
const int N=20;
int read(){ int x=0;std::cin>>x;return x; }

int n,m,g[N],bs[1<<N],w[N][N],conn[1<<N];
Int dp[1<<N];
inline int lowbit(int x){return x&(-x);}
int main(){
	n=read();m=read();
	for(int i=0;i<m;i++){
		int a=read(),b=read();
		a--;b--;
		g[a]|=(1<<b); g[b]|=(1<<a);
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) w[i][j]=read();

	for(int i=1;i<(1<<n);i++){int j=lowbit(i); bs[i]=bs[i^j]+1;}
	for(int i=0;i<n;i++) conn[1<<i]|=(1<<i);
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++)if(i&(1<<j)) conn[i]|=g[j];
	}


	for(int i=1;i<(1<<n);i++) dp[i]=-INF;
	for(int i=0;i<(1<<n)-1;i++){
		int k=bs[i],t=0;
		for(int j=0;j<n;j++) if((conn[i]&(1<<j))==0){
			t=i|(1<<j); dp[t]=std::max(dp[t],dp[i]+w[k][j]);
		}
	}
	Int ans=0; for(int i=0;i<(1<<n);i++) ans=std::max(ans,dp[i]);
	std::cout<<ans<<std::endl;
	std::cerr<<1.0*clock()/CLOCKS_PER_SEC<<std::endl;

	return 0;
}
