#include <bits/stdc++.h>
int read(){
	int x=0;char c;
	do{c=getchar();}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x;
}
typedef unsigned long long Int;
const int N=100;
int n,m;
Int g[N][N];
Int ans=0,vis[N],dep[N];
void dfs(int step,Int cost){
	if(cost>=ans) return ;
	if(step==n){ ans=cost; return ; }

	for(int i=1;i<=n;i++) if(vis[i]){
		for(int j=1;j<=n;j++) if(!vis[j]&&g[i][j]<Int(1e18)){
			dep[j]=dep[i]+1;
			vis[j]=1;
			dfs(step+1,cost+1ULL*dep[j]*g[i][j]);
			dep[j]=0;
			vis[j]=0;
		}
	}
}
void solve(int s){
	vis[s]=1; dep[s]=0;
	dfs(1,0);
	vis[s]=0; dep[s]=0;
} 

int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=Int(1e18);

	for(int i=0;i<m;i++){
		int u=read(),v=read();Int w=read();
		g[u][v]=std::min(g[u][v],w);
		g[v][u]=std::min(g[v][u],w);
	}
	ans=Int(1e18);
	for(int i=1;i<=n;i++) solve(i);
	std::cout<<ans<<std::endl;
	return 0;
}
