#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, cnt=0;
    cin>>n;
    vector<double> v(n+1, 0);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            for(int k=1;k<=n;k++) {
                if(abs(v[i]+v[j]-v[k])<0.00000000001) {
                    cnt++;
                    //cerr<<i<<j<<k;
                }
            }
        }
    }
    cout<<cnt;
}
