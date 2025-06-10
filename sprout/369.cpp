#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int l, r;
};
int mod=1e9+7;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, k;
    cin>>n>>a>>b>>k;
    int psum[2001][2001]={0};
    node range[2001];
    psum[a][0]=1;
    for(int i=1;i<=n;i++) {
        range[i]={2001,0};
        for(int j=1;j<=n;j++) {
            if(abs(i-j)<abs(j-b)) range[i].l=min(j, range[i].l), range[i].r=max(j, range[i].r);
        }
        //cerr<<range[i].l<<" "<<range[i].r<<'\n';
    } 
    for(int i=1;i<=n;i++) psum[i][0]=psum[i-1][0]+psum[i][0];
    for(int i=1;i<=k;i++) {
        for(int x=1;x<=n;x++) {
                if(range[x].l!=2001&&range[x].r!=0) psum[x][i]=(psum[range[x].r][i-1]-psum[range[x].l-1][i-1]+psum[x-1][i-1]-psum[x][i-1]+2*mod)%mod;
                psum[x][i]=(psum[x-1][i]+psum[x][i])%mod;
                //cerr<<psum[x][i]-psum[x-1][i]<<" ";
        }
        //cerr<<'\n';
    }
    cout<<(psum[n][k])%mod;
}
