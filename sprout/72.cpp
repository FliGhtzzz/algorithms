#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve() {
    int n, k;
    cin>>n;
    n--;
    stack<pair<int, int>> s;
    cin>>k;
    s.push({k, 0});
    while(n--) {
        cin>>k;
        if(s.top().second) {
            if(k>s.top().first) s.push({k, 0});
            else s.pop(), s.push({k, 1});
        }
        else {
            if(k<s.top().first) s.push({k, 1});
            else s.pop(), s.push({k, 0});
        }
    }
    cout<<s.size()-(int)(!(s.size()&1))<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
