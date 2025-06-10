#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_bas::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, a;
    cin>>n>>q;
    vector<int> v(1020, 0), b(1020, 0);
    for(int i=2;i<=n+1;i++) {
        cin>>v[i];
    }
    for(int i=2;i<=n+1;i++) {
        cin>>b[i];
    }
    while(q--) {
        cin>>a;
        a++;
        int ans=0;
        for(int i=a-1;i<=a+1;i++) {
            int cnt=0;
            cnt+=(b[i-1])+(b[i+1]);
            ans+=v[i]*pow(2, cnt);
        }
        cout<<ans<<'\n';
    }
}
