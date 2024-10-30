    #include<bits/stdc++.h>
    using namespace std;
    signed main() {
        string a, b;
        cin>>a>>b;
        int l=a.size(), m=b.size();
        a=" "+a, b=" "+b;
        vector<vector<int>> dp(2, vector<int>(2010, 0));
        for(int i=1;i<=l;i++) {
            for(int j=1;j<=m;j++) {
                if(a[i]==b[j]) dp[i&1][j]=dp[(i&1)^1][j-1]+1; //i&1->i是奇數偶數? 1是奇數0 是偶數 (i&1)^1可以取反 
                else dp[i&1][j]=max(dp[(i&1)^1][j], dp[i&1][j-1]);
            }
        }
        cout<<dp[l&1][m];
    }