#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> dp(m+1, vector<int>(k+1, 0));
    vector<int> w(n+1, 0), v(n+1, 0);
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=n;i++) {
        for(int j=m;j>=w[i];j--) {
            for(int u=1;u<=k;u++) {
                dp[j][u]=max(dp[j][u], dp[j-w[i]][u-1]+v[i]);
        
            }
        }
    }
    cout<<dp[m][k]<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}


