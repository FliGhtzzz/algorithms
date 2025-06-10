#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=1e6+3;
int f(int x) {
    int res=1, expo=mod-2;
    while(expo) {
        if(expo&1) res=(res*x)%mod;
        x=(x*x)%mod;
        expo>>=1;
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a, b;
    cin>>a>>b;
    int t=max(a, b);
    vector<int> c(t+2, 0), d(t+2, 0);
    c[0]=d[0]=1;
    for(int i=1;i<=t;i++) {
        c[i]=(i*c[i-1])%mod;
    }
    d[t]=f(c[t]);
    for(int i=t-1;i>=1;i--) {
        d[i]=(d[i+1]*(i+1))%mod;
    }
    cout<<(c[a]*d[b]%mod * d[a-b]%mod)%mod<<'\n';
}

