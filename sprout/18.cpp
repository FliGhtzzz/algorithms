#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1, 0), b(n+1, 0);
    stack<int> s;
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        a[i]=i;
    }
    for(int i=1, j=1;i<=n;i++) {
        s.push(a[i]);
        while(s.size()&&s.top()==b[j]) {
            s.pop(), j++;
            //cerr<<j<<" ";
        }
        if(j>=n) {cout<<"Yes\n";return;}
    }
    cout<<"No\n";
    return;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}

