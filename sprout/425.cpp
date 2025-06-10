#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int id, val;
};
int INF=-1e18;
signed main() {
#ifdef DEBUG
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    freopen("err.out","w",stderr);
#endif
    int n;
    cin>>n;
    stack<node> a, b;
    a.push({0, INF});
    b.push({n+1, INF}); 
    vector<int> l(n+5, 0), r(n+5, 0), v(n+5, 0);
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1, j=n;i<=n;i++, j--) {
        while(b.top().val>=v[j]) b.pop();
        while(a.top().val>=v[i]) a.pop();
        r[i]=a.top().id;
        l[j]=b.top().id;
        b.push({j, v[j]});
        a.push({i, v[i]});
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        ans=max(ans, (l[i]-r[i]-1)*v[i]);
    }
    cout<<ans;
}

