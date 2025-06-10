#include<bits/stdc++.h>
using namespace std;
signed main() {
    int a[10000000];
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin>>s;
    int t=s.size();
    s=" "+s;
    vector<int> len;
    for(int i=1;i*i<=t;i++) {
        if(t%i==0) len.push_back(i), len.push_back(t/i);
    }
    int mn=t;
    for(int i:len) {
        bool imp=0;
        for(int j=1;j<=t;j+=i) {
            if(imp) break;
            for(int k=j;k<j+i;k++) {
                if(s[k]!=s[k-j+1]) {imp=1;break;}
            }
        }
        if(!imp) mn=min(mn, i);
    }
    cout<<mn;
}

