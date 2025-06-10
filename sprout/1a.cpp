#include<bits/stdc++.h>
using namespace std;
#define int long long
int INF=1e18;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    pair<int, int> ans{INF, INF}, mxx={INF, 0};
    cin>>n;
    int a[4010], b[4010]={0}, sm=0, mx=0, mn=n+1;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        b[i]=b[i-1]+a[i];
        sm+=a[i];
        if(b[i]<0) mx=max(mx, i), mn=min(mn, i), mxx=min(mxx, {b[i], i});
    }
    if(sm<0) {cout<<-1;return 0;}
    int idx=0, now=INF;
    for(int i=1;i<=mn;i++) if(a[i]<now) now=a[i], idx=i; 
    if(idx==n+1) {cout<<"1 1\n";return 0;}
    for(int j=mx+1;j<=n;j++) {
        if(mxx.first+a[j]-a[idx]>=0) ans=min(ans, {idx, j});
            //cerr<<mxx.first+a[j]-a[i]<<" "<<b[j]-a[j]+a[i]-b[i]<<'\n';
        }
    if(ans.first!=INF) cout<<ans.first<<" "<<ans.second;
    else cout<<-1;
}
    
