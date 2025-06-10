#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, a, b;
    cin>>n;
    vector<int> v(n+1, 0);
    for(int i=1;i<=n;i++) cin>>v[i];
    cin>>a>>b;
    int sum=a+b;
    for(int i=2;i<=n;i++) {
        sum+=min((v[i]-v[i-1])*a, a+b);
    }
    cout<<sum;
}
