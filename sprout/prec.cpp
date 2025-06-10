#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s, t, s1, s2, temp;
    cin>>s;
    int q;
    cin>>q;
    while(q--) {
        cin>>s1>>temp>>s2;
        bool x=0;
        string ne;
        if(!s.find(s1)) continue;
        for(int i=0, l=s.size(), l1=s1.size();i<l;i++) {
            //cerr<<i<<" ";
            bool same=1;
            if(!x) { 
            for(int j=i;j-i<l1;j++) {
                if(s[j]!=s1[j-i]) {
                    same=0;
                    break;
                }
            }
            if(same) {
                x=1;
                i+=l1;
                ne=ne+s2;
                for(;i<l;i++) ne.push_back(s[i]);
            }
            else {
                ne.push_back(s[i]);
            }
            }
            else {
                ne.push_back(s[i]); 
            }
        }
        s=ne;
        //for(char o:s) cerr<<o;
    }
    for(char o:s) cout<<o;
}


