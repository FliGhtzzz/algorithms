#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, INF=1e9;
vector<vector<int>> dp(3, vector<int>(1000000, INF));
vector<int> v(1000000);
int dfs(int i, int l) {
    if(i<1||i>n) return -1;
    if(dp[l][i]!=INF) return dp[l][i];
    if(i==n) {
        if(l==0&&v[i-1]==1&&v[i-2]==0) return dp[0][i]=dfs(i-2, l)+1;
        else if(l==0) return dp[0][i]=0;
        if(l==1) return dp[1][i]=(int)(1-v[i-1]);
        if(l==2) return dp[2][i]=0;
    }
    else if(i==1) {
        if(l==0) return dp[0][i]=0;
        if(l==1) return dp[1][i]=(int)(1-v[i+1]);
        if(l==2&&v[i+1]==1&&v[i+2]==0) return dp[2][i]=dfs(i+2, l)+1;
        else if(l==2) return dp[2][i]=0;
    }
    else if(l==0) {
        if(v[i-1]==1&&v[i-2]==0) return dp[0][i]=dfs(i-2, l)+1;
        else return dp[0][i]=0;
    }
    else if(l==1) return dp[1][i]=(int)(1-v[i-1]||1-v[i+1]);
    else if(l==2) {
        if(v[i+1]==1&&v[i+2]==0) return dp[2][i]=dfs(i+2, l)+1;
        else return dp[2][i]=0;
    }
    return dp[l][i];
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<int> ans(n+1, 0);
    dp[0][1]=0, dp[2][n]=0;
    for(int i=1;i<=n;i++) cin>>v[i];
    if(n==1&&v[1]) {cout<<0;return 0;}
    for(int i=1;i<=n;i++) {
        if(v[i]) {
            if(i==1) ans[i]=max(dfs(i, 2), dp[1][i]=(int)(1-v[i+1]));
            else if(i==n) ans[i]=max(dfs(i, 0), dp[1][i]=(int)(1-v[i-1]));
            for(int j=0;j<=2;j++) if(dfs(i, j)!=INF) {
                ans[i]=max(ans[i], dfs(i, j));
            }
        }
        else ans[i]=-1;
    
    }
    /*
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=2;j++) {
            cerr<<dp[j][i]<<" ";
        }
        cerr<<'\n';
    }
    cerr<<'\n';*/
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}
