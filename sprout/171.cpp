#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[18][1<<17], dis[18][18];
void solve() {
    int n, ans=0x3f3f3f3f;
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    cin>>n;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            cin>>dis[i][j];
           dis[j][i]=dis[i][j];
        }
    }
    dp[0][0]=0;
    dp[1][1]=0;
    for(int i=1;i<(1<<n);i+=2) {
        for(int j=1;j<n;j++) { 
            if(i&(1<<j)) {
                for(int k=0;k<n;k++) {
                    if((i-(1<<j))&(1<<k)) dp[j+1][i]=min(dp[j+1][i], dp[k+1][i-(1<<j)]+dis[j+1][k+1]);
                }
            }
        }
    }
    for(int i=2;i<=n;i++) ans=min(ans, dp[i][(1<<n)-1]+dis[i][1]);
    cout<<ans<<'\n';
}
signed main() {
    int q;
    cin>>q;
    for(;q--;) solve();
}
