#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
//vector<pair<int, int>> v(100010, {0, 0});
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}
void solve() {
    int x, mx=0, time=0;
    cin>>x;
    vector<pair<int, int>> v(x);
	for(int i=0;i<x;i++) {
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(), v.end(), [&](auto a, auto b) {return a.second>b.second;});
	for(int i=0;i<x;i++) {
		time+=v[i].first;
        mx=max(mx, time+v[i].second);
	}
	cout<<mx<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
