#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, sum=0;
    cin>>n;
    vector<int> a(n+5, 0);
    for(int i=2;i<=n;i++) a[i]=i;
    for(int i=2;i*i<=n;i++) {
        if(a[i]==i) for(int j=i;j<=n;j+=i) {
            if(a[j]==j) a[j]=i;
        }
    }
    for(int i=2;i<=n;i++) sum+=a[i];
    cout<<sum;
}
