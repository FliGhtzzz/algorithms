#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int, int>
#define F first 
#define S second 
int INF=1e18;
signed main() {
    int n, m, q, a, b, c, nei, wei;
    cin>>n>>m>>q;
    vector<int> disa(200010, INF), disb(200010, INF);
    vector<pair<int, int>> ab[200010], ba[200010];
    for(int i=1;i<=m;i++) {
        cin>>a>>b>>c;
        ab[a].push_back({b, c});
        ba[b].push_back({a, c});
    }
    priority_queue<pll, vector<pll>, greater<pll>> Q;
    bitset<200010> visited;
    Q.push({0, 1});
    while(!Q.empty()) {
        auto it=Q.top();
        Q.pop();
        int v=it.second;
        if(visited[v]) continue;

            for(auto it : ab[v]) {
            nei=it.F;
            wei=it.S;
            if(disa[nei]>disa[v]+wei) {
                disa[nei]=disa[v]+wei;
                Q.push({disa[nei], nei});
            }
        }
    }
    Q.push({0, n});
    visited.reset();
    while(!Q.empty()) {
        auto it=Q.top();
        Q.pop();
        int v=it.second;
        if(visited[v]) continue;
            for(auto it : ba[v]) {
            nei=it.F;
            wei=it.S;
            if(disb[nei]>disb[v]+wei) {
                disb[nei]=disb[v]+wei;
                Q.push({disb[nei], nei});
            }
        }
    }
    while(q--) {
        cin>>a>>b;
        cout<<min(disa[n], disa[a]+1+disb[b])<<'\n';
    }
}

