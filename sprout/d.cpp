#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n, m, q, mn=1000000;
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++) {
        if(q%i==0) mn=min(mn, q/i+i);
    }
    cout<<mn*2;
}
