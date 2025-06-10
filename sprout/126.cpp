#include<bits/stdc++.h>
using namespace std;
//#define int long long
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, n, dp[100010]={0}, rgb[4][4][100010]={0}, mod=1000007;
    rgb[1][1][1]=1, rgb[2][2][1]=1, rgb[3][3][1]=1, dp[1]=3;
    for(int i=2;i<=100000;i++) {
        for(int j=1;j<=3;j++) {
            rgb[j][1][i]=(rgb[j][1][i-1]+rgb[j][2][i-1]+rgb[j][3][i-1])%mod;
            rgb[j][2][i]=(rgb[j][1][i-1]+rgb[j][2][i-1])%mod;
            rgb[j][3][i]=(rgb[j][1][i-1]+rgb[j][3][i-1])%mod;
            dp[i]=(dp[i]+rgb[j][1][i]+rgb[j][2][i]+rgb[j][3][i])%mod;
        }
        dp[i]=(dp[i]-rgb[2][3][i]-rgb[3][2][i]+mod+mod)%mod;
    }
    cin>>q;
    while(q--) {
        cin>>n;
        cout<<dp[n]<<'\n';
    }
}

