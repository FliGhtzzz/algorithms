#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
#define X first 
#define Y second
#define int long long
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> table;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, cnt=0, l;
    cin>>n;
    vector<pair<int, int>> nd(n+5, {0, 0});
    for(int i=1;i<=n;i++) cin>>nd[i].X>>nd[i].Y;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            l=((nd[i].X-nd[j].X)*(nd[i].X-nd[j].X)+(nd[i].Y-nd[j].Y)*(nd[i].Y-nd[j].Y));
            cnt+=table[l];
            table[l]++;
        }
    }
    cout<<cnt;
}
