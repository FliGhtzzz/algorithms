#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n, W, mx=0;
    cin>>n>>W;
    int w[n+1], p[n+1];
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) { //每個物品都跑過一遍
        //以j表示當前背包重量限制
        for (int j=0;j<w[i]; j++) //當前背包重量限制<w[i]->根本不能選
            dp[i][j]=dp[i-1][j]; 
        for (int j=w[i];j<=W;j++) 
            dp[i][j]=max(dp[i-1][j-w[i]]+p[i], dp[i-1][j]);
    }
    cout<<dp[n][W];
}