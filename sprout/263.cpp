#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200010], cost(200010, 0);
int n, a, b;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
int dfs(int now, int par) {
    int sz=1, temp=0;
    for(int i:adj[now]) {
        if(i==par) continue;
        temp=dfs(i, now);
        sz+=temp;
        cost[now]=max(cost[now], temp);
    }
    cost[now]=max(cost[now], n-sz);
    return sz;
}
void solve() {
    cin>>n;
    for(int i=2;i<=n;i++) {
        a=read(), b=read();
        adj[a].push_back(b);adj[b].push_back(a);
    }
    dfs(0, -1);
    int mn=1e9, ans=0;
    for(int i=0;i<n;i++) { 
        if(cost[i]<mn) mn=cost[i], ans=i;
        adj[i].clear(), cost[i]=0;
    }
    write(ans);
    cout<<'\n';
}
signed main() {
    int q;
    q=read();
    while(q--) solve();
}
