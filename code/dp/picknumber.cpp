#include<bits/stdc++.h>
using namespace std;
int a[100010], dp[1000010];
signed main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1]=a[1];
    for(int i=2;i<=n;i++) dp[i]=max(dp[i-1], dp[i-2]+a[i]);
    cout<<dp[n];
}