#include<bits/stdc++.h>
using namespace std;
int dp[20010], a, b, n, m;
void solve() {
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vector<int> val;
        for (int j = 1; b > 0; j <<= 1) {
            int take = min(j, b);
            val.push_back(a * take);
            b -= take;
        }
        for (int coin : val) {
            for (int j = m; j >= coin; j--) {
                if (dp[j - coin]) dp[j] = 1;
            }
        }
    }
    if (dp[m]) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
