#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
vector<int> boss(10), sz(10);
void build_dsu(int x) {
    boss.resize(x+1, 0);
    sz.resize(x+1, 1);
    for(int i=0;i<=x;i++) boss[i]=i;
}
signed find(int x) {
    if(boss[x]==x) return x;
    return boss[x] = find(boss[x]);  //路徑壓縮 詳細可以去搜尋反阿克曼函数
}
void Union(int a, int b) {  //可以使每次合併一定是小的合到大的
    int fa= find(a), fb=find(b);   
    if(sz[fb] > sz[fa]) swap(fa, fb);
    sz[fa]+=sz[fb];
    boss[fb]=fa;
}
signed main() {
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