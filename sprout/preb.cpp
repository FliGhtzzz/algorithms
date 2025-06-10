#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> v(n+1, 0), ans(n+1, 0), ex(n+1, 0);
    for(int i=1;i<=n;i++) cin>>v[i];
    int now=1;
    for(int i=1;i<=n;i++) {
        if(n-i+1==k-now+1) {
            if(ans[i-1]==now&&v[i]<=v[i-1]) {cout<<-1;return 0;}
            else ans[i]=now++;
        }
        else if(v[i]>v[i-1]) {
            //if(n-i+1==k-now+1) ans[i]=now++;
            ans[i]=now;
        }
        else ans[i]=++now;
        cerr<<ans[i]<<" ";
    }
    if(ans[n]!=k) {cout<<-1;return 0;}
    for(int i=1;i<=n;i++) {
        ex[ans[i]]=1;
        if(ans[i]>k) {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=k;i++) {
        if(ex[i]==0) {
            cout<<-1;
            return 0;
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
