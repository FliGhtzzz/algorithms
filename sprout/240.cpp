#include<bits/stdc++.h>
using namespace std;
signed main() {
    string s;
    cin>>s;
    int n=s.size(), mn;
    mn=n;
    bool imp=0;
    for(int i=1;i<=n;i++) {
        imp=0;
        for(int j=0;j<i;j++) {
            if(s[j]!=s[n-i+j]) {imp=1;break;}
        }
        if(!imp) mn=min(mn, i);
    }
    cout<<mn;
}
