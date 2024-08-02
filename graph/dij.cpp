#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pll pair<long long, long long>
const long long INF=8e18;
bool visited[510]={0}; //
vector<pair<int, long long>> adj[1000];
long long dis[510]={0};
priority_queue<pll, vector<pll>, greater<pll>> Q;
int n, src, nei, wei; //點和初始點
void build_dij() {
        for(int i=1;i<=n;i++) dis[i]=INF;
        dis[src]=0;
        Q.push({0, src});
}
void dij() {
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
                Q.push({-dis[nei], nei});
            }
            }
    }
}
signed main() {
    fast;
    int x, a ,b ,c;
    src=1; //change able
    cin>>n>>x;
    while(x--) {
        cin>>a>>b>>c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    dij();
    for(int i=1;i<=n;i++) {
        cout<<dis[i]<<" ";
    }
    return 0;
}