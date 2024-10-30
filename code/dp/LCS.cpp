#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3;
signed main() {
    int l, m;
    string a, b;
    cin>>a>>b;
    a=" "+a, b=" "+b;
    l=a.size(), m=b.size(); //把字串改成1-base 方便之後DP的實作
    vector<vector<int>> dp(MAXN, vector<int>(MAXN, 0)); //DP表格
    for(int i=1;i<l;i++) {
        for(int j=1;j<m;j++) {
            if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1; 
            else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[l-1][m-1];
}