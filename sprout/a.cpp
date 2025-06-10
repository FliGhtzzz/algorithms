#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1, 0);
    vector<pair<int, int>> ans;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    while(n>=1) {
        int mx=0, idx=0;
        for(int j=1;j<n;j++) {
            if(v[j]>mx) mx=v[j], idx=j;
        }
        if(v[n]!=mx&&idx!=0&&mx>v[n]) {
        v[idx]=v[n];
        v[n]=mx;
        ans.push_back({idx, n});
        }
        n--;
    }
    cout<<ans.size()<<'\n';
    for(auto i:ans) {
        cout<<i.first<<" "<<i.second<<'\n';
    }
}
