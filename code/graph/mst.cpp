#include<bits/stdc++.h>
using namespace std;
#define int long long
struct e{
    int x, y;
    int cost;
};
bool cmp(e x, e y){
    return x.cost < y.cost;
}
int n, m, x, y, c, todo, p[200010];
long long ans;
int find(int a){
    if (p[a] == a) return a;
    else {
        p[a] = find(p[a]);
        return p[a];
    }
}
vector <e> v;
signed main() {
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> m){
        todo = n-1;
        ans = 0;
        v.clear();
        for (int i = 0; i < n; i++){
            p[i] = i;
        }
        for (int i = 0; i < m; i++){
            cin >> x >> y >> c;
            v.push_back({x, y, c});
        }
        sort(v.begin(), v.end(), cmp);
        for (e tmp:v){
            x = find(tmp.x);
            y = find(tmp.y);
            if (x == y) continue;
            else {
                p[y] = x;
                todo -= 1;
                ans += tmp.cost;
            }
        }
        if (todo == 0) cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}