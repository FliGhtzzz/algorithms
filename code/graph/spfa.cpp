#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define pii pair<long, long>
#define elif else if
random_device rd;
mt19937 randommm(rd());
/********************************************************/
/********************************************************/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<int, int, custom_hash> cnt;
/********************************************************/
/********************************************************/
const int MAXN=1e5+5, INF=1e18;
void solve() {
    int n, m, a, b, c;
    cin>>n>>m;
    vector<pii> adj[MAXN];
    vector<int> dis(MAXN, INF), vst(MAXN, 0);
    bitset<MAXN> inq;
    for(int i=1;i<=m;i++) {
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    queue<int> spfa;
    spfa.push(1);
    bool imp=0;
    dis[1]=0;
    while(!spfa.empty()) {
        int now=spfa.front();spfa.pop();
        vst[now]++;
        if(vst[now]>n) {
            imp=1;
            break;
        }
        inq[now]=0;
        for(auto it:adj[now]) {
            int to=it.first, wei=it.second;
            if(dis[to]<dis[now]+wei) {
                dis[to]=dis[now]+wei;
                if(!inq[to]) {spfa.push(to);inq[to]=1;}
            }
        }
    }
    if(imp) cout<<-1;
    else cout<<dis[n];
}
signed main() {
    int q=1;
    while(q--) solve();
}