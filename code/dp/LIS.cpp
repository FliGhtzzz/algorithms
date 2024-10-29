#include<bits/stdc++.h>
using namespace std;
int n, a[2010], dp[2010], z=0;
signed main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0]=0, a[0]=0, dp[1]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(a[j]<a[i]) dp[i]=max(dp[i], dp[j]+1);
        }
        z=max(z, dp[i]);
    }
    cout<<z;
}