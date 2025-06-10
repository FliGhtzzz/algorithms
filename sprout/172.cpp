#include<bits/stdc++.h>
using namespace std;
#define int long long
int val[100010], dp[100010], w[100010];
void solve() {
    int n, k, c;
    cin>>n>>k>>c;
    for(int i=1;i<=n;i++) cin>>val[i];
    dp[1]=val[1];
    w[1]=1;
    for(int i=2, l=1, r=2;i<=n;i++) { 
        while(w[l]+k<i) l++;
        //cerr<<dp[w[l]]<<"haha ";
        dp[i]=val[i]+max(dp[w[l]]+w[l]*c-(i)*c, (int)0);
        while(dp[w[r-1]]+w[r-1]*c<dp[i]+c*(i)&&r>l) r--;
        w[r]=i;
        r++;
    }
    int ans=(-1)*(0x3f3f3f3f);
    for(int i=1;i<=n;i++) {ans=max(dp[i], ans);}
    cout<<ans<<'\n';
}
signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}
