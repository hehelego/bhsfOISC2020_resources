#include <bits/stdc++.h>
typedef unsigned long long Int;
int read(){
	int x=0;char c;
	do{c=getchar();}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	return x;
}
const int N=800000+10;
int n,m,a[N];
struct T{ int sum;
	Int pre[3],suf[3],cnt[3];
	T():sum(0){
		pre[0]=pre[1]=pre[2]=0;
		suf[0]=suf[1]=suf[2]=0;
		cnt[0]=cnt[1]=cnt[2]=0;
	}
}t[N];
int fix(int a){ return (a%3+3)%3; }
T single(int x){
	T t; t.sum=x;
	t.pre[x]=t.suf[x]=t.cnt[x]=1;
	return t;
}
T empty(){T t; return t;}
T merge(const T&a,const T&b){
	T c; c.sum=(a.sum+b.sum)%3;
	for(int i=0;i<3;i++){
		c.pre[i]=a.pre[i]+b.pre[fix(i-a.sum)];
		c.suf[i]=b.suf[i]+a.suf[fix(i-b.sum)];

		c.cnt[i]=a.cnt[i]+b.cnt[i];
		for(int j=0;j<3;j++) c.cnt[i]+=(a.suf[j]*b.pre[fix(i-j)]);
	}
	return c;
}
void build(int o,int L,int R){
	if(L==R){t[o]=single(a[L]); return;}
	int mid=(L+R)>>1,ls=o<<1,rs=ls|1;
	build(ls,L,mid); build(rs,mid+1,R);
	t[o]=merge(t[ls],t[rs]);
}
T qry(int o,int L,int R,int l,int r){
	if(L>r||R<l) return empty();
	if(l<=L&&R<=r) return t[o];
	int mid=(L+R)>>1,ls=o<<1,rs=ls|1;
	return merge(qry(ls,L,mid,l,r),qry(rs,mid+1,R,l,r));
}

int main(){
	n=read();m=read(); for(int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);

	while(m--){
		int l=read(),r=read();
		printf("%llu\n",qry(1,1,n,l,r).cnt[0]);
	}
	std::cerr<<1.0*clock()/CLOCKS_PER_SEC<<std::endl;
	return 0;
}
