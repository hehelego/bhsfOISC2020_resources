#include <bits/stdc++.h>
using std::min;
using std::max;
int read(){
    int x=0;char c;
    do{c=getchar();}while(!isdigit(c));
    do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
    return x;
}
const int N=130000+10;
const int M=800+10;
const double eps=1e-7;
int n,m,bs,bcnt,bel[N];
int L[M],R[M],size[M];
double slope[N],seq[M][M];
void rebuild(int blk){
    size[blk]=0;
    for(int i=L[blk];i<=R[blk];i++){
        if(fabs(slope[i])<eps) continue;
        if(size[blk]==0||seq[blk][size[blk]]<slope[i])
            seq[blk][++size[blk]]=slope[i];
    }
}
inline void upd(int x,int y){ double k=1.0*y/x; slope[x]=k; rebuild(bel[x]); }
int solve(){
    double now=0;
    int ret=0;
    for(int i=1;i<=bcnt;i++){
        if(size[i]==0) continue;
        int l=1,r=size[i],mid=0,ans=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(seq[i][mid]>now){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        if(ans) ret+=max(0,(size[i]-ans+1));
        now=max(now,seq[i][size[i]]);
    }
    return ret;
}
int main(){
    n=read();m=read();
    bs=ceil(sqrt(n)); bcnt=n/bs+(n%bs>0);
    for(int i=1;i<=n;i++) bel[i]=(i-1)/bs+1;
    for(int i=1;i<=bcnt;i++){
        L[i]=(i-1)*bs+1;
        R[i]=i*bs;
    }R[bcnt]=n;

    int x,y;
    while(m--){
        x=read();y=read();
        upd(x,y);
        printf("%d\n",solve());
    }
    return 0;
}
