#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, q, a, b, t=0;
bitset<200010> visited;
vector<int> deep(200010, 0), chi[200010];
vector<vector<int>> dp(26, vector<int>(200010)); 
void dfs(int node, int d=0) {
    deep[node]=d;
    for(int i:chi[node]) {
        if(!visited[i]) {
            visited[i]=1;
            dfs(i, d+1);
        }
    }
}
signed jump(int node, int step) {
    for(int i=0;i<26;i++) {
        int j=1<<i;
        if(j&step) node=dp[i][node];
    }
    return node;
}
signed main() {
    cin>>n>>q;
    for(int i=2;i<=n;i++) {
        cin>>dp[0][i];
        chi[dp[0][i]].push_back(i);
    }
    dp[0][1]=1;
    for(int i=1;i<26;i++) 
        for(int j=1;j<=n;j++) 
            dp[i][j]=dp[i-1][dp[i-1][j]];
    visited[1]=1;
    dfs(1);
    while(q--) {
        cin>>a>>b;
        if(a==b) cout<<a<<'\n';
        else {
            if(deep[a]<deep[b]) swap(a, b);
            a=jump(a, deep[a]-deep[b]);
            if(a==b) {cout<<a<<'\n'; continue;}
            for(int i=25;i>=0;i--) if(dp[i][a]!=dp[i][b]) {
                a=dp[i][a], b=dp[i][b]; 
            }
            cout<<dp[0][a]<<'\n';
        }
    }
}