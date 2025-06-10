#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, a, b, last;
    cin>>n>>q;
    vector<int> f(n+5, 0), l(n+5, 0);
    l[0]=1;
    for(int i=1;i<=n+2;i++) {
        f[i]=i-1, l[i]=i+1;
    }
    while(q--) {
        cin>>a>>b;
        if(a&1) {
            if(f[b]==0) continue;
            f[l[b]]=f[b];
            int temp=f[f[b]];
            l[f[f[b]]]=b;
            l[f[b]]=l[b];
            f[f[b]]=b;
            l[b]=f[b];
            f[b]=temp;
        }
        else {
            l[f[b]]=l[b];
            f[l[b]]=f[b];
            f[b]=-1, l[b]=-1;
        }
    }
    int now=l[0];
    while(now<=n) {
        cout<<now<<" ";
        now=l[now];
    }
}

