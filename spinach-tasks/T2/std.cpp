#include <bits/stdc++.h>
typedef long long Int;
const Int INF=Int(1e15);
const int N=19;
int read(){ int x=0;std::cin>>x;return x; }

int n,m,g[N][N],bs[1<<N],w[N][N];
Int dp[1<<N];
inline int lowbit(int x){return x&(-x);}
int main(){
	n=read();m=read();
	for(int i=0;i<m;i++){
		int a=read(),b=read();
		a--;b--;
		g[a][b]=g[b][a]=1;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++) w[i][j]=read();

	for(int i=1;i<(1<<n);i++){
		int j=lowbit(i); bs[i]=bs[i^j]+1;
	}
	Int ans=0; for(int i=1;i<(1<<n);i++){
		dp[i]=-INF; int k=bs[i]-1;
		for(int j=0;j<n;j++) if(i&(1<<j)){
			dp[i]=std::max(dp[i],dp[i^(1<<j)]+w[k][j]);
		}
		ans=std::max(ans,dp[i]);
	}
	std::cout<<ans<<std::endl;
	std::cerr<<1.0*clock()/CLOCKS_PER_SEC<<std::endl;
	return 0;
}
