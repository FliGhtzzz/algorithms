#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}
void solve() {
    int x, mx=0, time=0;
    cin>>x;
    assert(x!=0);
    vector<pair<int, int>> v(x, {0, 0});
	for(int i=0;i<x;i++) {
		cin>>v[i].first>>v[i].second;
	}
	sort(v.rbegin(), v.rend());
	for(int i=0;i<x;i++) {
		time+=v[i].first;
        mx=max(mx, time+v[i].second);
	}
	cout<<mx<<'\n';
}
signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}

