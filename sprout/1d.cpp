#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> val(500010, 0);
vector<pair<int, int>> v[500010];
int n, m, a, b, c, cnt=0;
void dfs(int now, int fa, int p) {
    //cerr<<now<<" ";
    cnt++;
    p=min(val[now], p);
    for(auto i:v[now]) {
        if(i.first==fa) continue;
        if(p-i.second>0) dfs(i.first, now, p-i.second);
    }
    return;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<n;i++) {
        cin>>a>>b>>c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    int l=0, r=val[1]+1;
    dfs(1, 0, r);
    //cerr<<cnt<<"???\n";
    if(cnt<=m) {cout<<-1;return 0;}
    while(l<=r) {
        //cerr<<l<<" "<<r<<"HAHAHAHAAH\n";
        if(r-l<=5) {
            for(int i=l;i<=r;i++) {
                cnt=0;
                dfs(1, 0, i);
                if(cnt>m) {cout<<i-1;return 0;}
            } 
        }
        else {
            int mid=(l+r)>>1;
            cnt=0;
            dfs(1, 0, mid);
            if(cnt<=m) l=mid;
            else r=mid;
        }
    }
}
