#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
long long INF=1e18;
int n, m, s, e, f, a, b, c, d, cc;
int dis[105][105];
/*void dij() {
    build_dij();
    while(!Q.empty()) {
        auto it=Q.top();
        Q.pop();
        int v=it.second;
        if(visited[v]) continue;
            for(auto it : adj[v]) {
            nei=it.F;
            wei=it.S;
            if(dis[nei]>dis[v]+wei) {
                dis[nei]=dis[v]+wei;
                Q.push({dis[nei], nei});
            }
        }
    }
}*/
void solve() {
    cin>>n>>m>>s>>e>>f;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=INF;
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=m;i++) {
        cin>>a>>b>>c>>d>>cc;
        if(f>d) dis[a][b]=min(dis[a][b], d*c+(f-d)*cc);
        else dis[a][b]=min(dis[a][b], c*f);
    }
    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    cout<<dis[s][e]<<'\n';
}
signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}
