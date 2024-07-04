#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define pii pair<int, int>
#define S second
#define pq priority_queue
#define q queue
#define cl clear
#define elif else if
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
/********************************************************/
/********************************************************/
vector<int> boss(10), sz(10);
void build_dsu(int x) {
    boss.resize(x+1, 0);
    sz.resize(x+1, 1);
    for(int i=0;i<=x;i++) boss[i]=i;
}
signed find(int x) {
    if(boss[x]==x) return x;
    return boss[x] = find(boss[x]);
}
void Union(int a, int b) {
    int fa= find(a), fb=find(b);
    if(sz[fb] > sz[fa]) swap(fa, fb);
    sz[fa]+=sz[fb];
    boss[fb]=fa;
}
signed main() {
    fast;
    int x, y, a, b ,c;
    cin>>x>>y;
    build_dsu(x);
    while(y--) {
        cin>>a>>b>>c;
        if(a==1) Union(b, c);
        elif(find(b)==find(c)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}