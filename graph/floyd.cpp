#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>
#define pq priority_queue
#define q queue
#define cl clear
#define elif else if
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define pll pair<long long, long long>
#define ll long long
const long long INF=2e18;
/********************************************************/
/********************************************************/
int node, edge, s;
const int max_node=510;
ll dis[max_node][max_node]; //max_nodes
ll adj[max_node][max_node]; 
void make_inf() {
    for(int i=1;i<max_node;i++) {
        for(int j=1;j<max_node;j++) {
            dis[i][j]=INF;
            adj[i][j]=INF;
        }
    }
}
void build_floyd() {
    for(int i = 1; i <= node; i++) {
        for(int j = 1; j <= node; j++) {
            dis[i][j] = adj[i][j];  //初始化 才可以DP
        }
    }
    for(int i = 1; i <= node; i++)
        dis[i][i]=min(dis[i][i], (ll)0);  //自己到自己=0
    
    for(int k = 1; k <= node; k++) {
        for(int i = 1; i <= node; i++) {
            for(int j = 1; j <= node; j++) {
                 dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);  //DP to do floyd
            }
        }
    }
}
signed main() {
    fast;
    make_inf();
    cin>>node>>edge>>s;
    long long a, b, c;
    for(int i=0;i<edge;i++) {
        cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b], c);
        adj[b][a]=min(adj[b][a], c); //如果是無向圖，這行要保留，否則刪除
    }
    build_floyd();
    for(int i=0;i<s;i++) {
        cin>>a>>b;
        if(dis[a][b]==INF) cout<<-1<<'\n';
        else cout<<dis[a][b]<<'\n';
    }
    return 0;
}