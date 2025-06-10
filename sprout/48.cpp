#include<bits/stdc++.h>
using namespace std;
vector<int> sz(100010, 1), adj[100010], vis(100010, 0);
void dfs(int now, int par) {
    vis[now]=1;
    if(adj[now].size()==0) return;
    for(int i:adj[now]) {
        if(i==par) continue;
        dfs(i, now);
        sz[now]+=sz[i];
    }
}
void solve() {
    int n, m, a, b, q;
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i, 0);
    cin>>q;
    while(q--) {
        cin>>a;
        cout<<sz[a]<<'\n';
    }
    for(int i=1;i<=n;i++) adj[i].clear(), sz[i]=1;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
