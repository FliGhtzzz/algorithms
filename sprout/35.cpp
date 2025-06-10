#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, a, b;
    cin>>q;
    stack<int> t;
    while(q--) {
        cin>>a;
        if(a&1) {
            cin>>b;
            t.push(b);
        }
        else {
            if(t.size()) {cout<<t.top()<<'\n';t.pop();}
            else cout<<"empty!\n";
        }
    }
}

