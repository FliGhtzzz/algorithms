#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, dp[100010], temp, pre[100010];
    cin>>q;
    dp[2]=3, pre[0]=1, pre[2]=4;
    for(int i=4;i<=100000;i+=2) {
        dp[i]=(dp[i-2]*3+pre[i-4]*2)%1000007;
        pre[i]=pre[i-2]+dp[i];
    }
    while(q--) {
        cin>>temp;
        if(temp&1) cout<<"0\n";
        else cout<<dp[temp]<<'\n';
    }
}
