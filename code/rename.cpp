#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define pb push_back
#define pii pair<long, long>
#define elif else if
#define flightzz ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
random_device rd;
mt19937 randommm(rd());
/********************************************************/
/********************************************************/
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<int, int, custom_hash> cnt;
/********************************************************/
/********************************************************/
void solve() {
    int n, m;
    string s;
    cin>>s>>n>>m;
    for(int i=n;i<=m;i++) {
        if(i<10) {
            cout<<s<<"_0"<<i<<".in\n";
        }
        else {
            cout<<s<<"_"<<i<<".in\n";
        }
    }
    for(int i=n;i<=m;i++) {
        if(i<10) {
            cout<<s<<"_0"<<i<<".out\n";
        }
        else {
            cout<<s<<"_"<<i<<".out\n";
        }
    }
}
signed main() {
    flightzz;
    int q=1;
    while(q--) solve();
}