#include<bits/stdc++.h>
using namespace std;
int a[28];
bitset<600010> bs;
vector<priority_queue<int>> v(28); 
string s;
int sum=0, ls, t=0;
bool put=0;
bool putable(int i) {
    if(s[ls]==s[i]||a[s[i]-'a'+1]==0) return 0;
    for(int i=1;i<=26;i++) {
        if(sum&1) {
            if(a[i]==(sum>>1)+1) {
                cout<<v[i].top();
                a[i]--;
                bs[v[i].top()]=0;
                ls=v[i].top();
                put=1;
                v[i].pop();
                return 0;
            }
        }
        else {
            if(a[i]==sum>>1) {
                cout<<v[i].top();
                a[i]--;
                bs[v[i].top()]=0;
                ls=v[i].top();
                put=1;
                v[i].pop();
                return 0;
            }
        }
    }
    return 1;
}
void solve() {
    cin>>s;
    int l=s.size();
    s=" "+s;
    for(int i=1;i<=26;i++) a[i]=0;
    for(int i=0;i<=l;i++) bs[i]=1;
    t=1;
    for(char c:s) {
        a[c-'a'+1]++;
        v[a[c-'a'+1]].push(t++);
    }
    for(int i=1;i<=26;i++) {
        if(l&1) {
            if(a[i]>(l>>1)+1) {cout<<"-1\n";return;}
        }
        else {
            if(a[i]>(l>>1)) {cout<<"-1\n";return;}
        }
    }
    sum=l;
    ls=-1;
    for(int i=1;i<=l;i++) {
        if(putable(i)) {
            if(put) continue;
            cout<<i<<" ";
            a[s[i]-'a'+1]--;
            bs[i]=0;
            ls=i;
            v[s[i]].pop();
        }
        else {
            for(int j=l;j>=1&&!put;j--) {
                if(putable(j)) {
                    if(put) break;
                    cout<<j<<" ";
                    a[s[j]-'a'+1]--;
                    //cerr<<a[(s[j]-'a'+1)];
                    bs[j]=0;
                    ls=j;
                    v[s[i]].pop();
                    break;
                }
            }
        }
    }
    cout<<'\n';
}
signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}
