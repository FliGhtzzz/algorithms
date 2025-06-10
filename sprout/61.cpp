#include<bits/stdc++.h>
using namespace std;
int v[15], n;
void ans(int cnt, int cur, int cho) {
    if(cnt==6) {
        for(int i=0, fnd=0;i<=13;i++) {
            int j=1<<i;
            if(j&cho&&fnd<5) {cout<<v[i+1]<<" ";fnd++;}
            else if(j&cho) cout<<v[i+1]<<'\n';
        }
        return;
    }
    if(cur>=n) return;
    ans(cnt+1, cur+1, cho|(1<<cur));
    ans(cnt, cur+1, cho);
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i];
    ans(0, 0, 0);
}

signed main() {
    if(cur>n) return;dddd
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
