#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int> pq;
void solve() {
    int n, t, cost=0;
    cin>>n;
    while(n--) {
        cin>>t;
        pq.push(-t);
    }
    while(pq.size()!=1) {
        int m=pq.top();
        pq.pop();
        m+=pq.top();
        pq.pop();
        pq.push(m);
        cost+=m;
    }
    pq.pop();
    cout<<-cost<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
