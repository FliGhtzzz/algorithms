#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_N = 5e5+10;
const int INF = 2e18;
//0-based 重邊
struct EdgeBCC{
    int n, m, dep, sz;
    vector<vector<pair<int, int>>> G;
    vector<vector<int>> bcc;
    vector<int> dfn, low, stk, isBridge, bccId;
    vector<pair<int, int>> edge, bridge;

    EdgeBCC(int _n) : n(_n), m(0), sz(0), dfn(n), low(n), G(n), bcc(n), bccId(n) {}

    void add_edge(int u, int v) {
        edge.push_back({u, v});
        G[u].push_back({v, m});
        G[v].push_back({u, m++});
    }

    void dfs(int now, int pre) {
        dfn[now] = low[now] = ++dep;
        stk.push_back(now);

        for (auto [x, id] : G[now]){
            if (!dfn[x]){
                dfs(x, id);
                low[now] = min(low[now], low[x]);
            }else if (id!=pre){
                low[now] = min(low[now], dfn[x]);
            }
        }

        if (low[now]==dfn[now]){
            if (pre!=-1) isBridge[pre] = true;
            int u;
            do{
                u = stk.back();
                stk.pop_back();
                bcc[sz].push_back(u);
                bccId[u] = sz;
            } while (u!=now);
            sz++;
        }
    }

    void get_bcc() {
        isBridge.assign(m, 0);
        dep = 0;
        for (int i=0 ; i<n ; i++){
            if (!dfn[i]) dfs(i, -1);
        }

        for (int i=0 ; i<m ; i++){
            if (isBridge[i]){
                bridge.push_back({edge[i].first , edge[i].second});
            }
        }
    }
};
signed main() {
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, a, b;
    cin>>n>>m;
    EdgeBCC bcc(n);
    for(int i=1;i<=m;i++) {
        cin>>a>>b;
        bcc.add_edge(a, b);
    }
    bcc.get_bcc();
    cout<<bcc.sz<<'\n';
    for(int i=0;i<bcc.sz;i++) { //0-based
        cout<<bcc.bcc[i].size()<<' ';
        for(auto v:bcc.bcc[i]) cout<<v<<' ';
        cout<<'\n';
    }
}