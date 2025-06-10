#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    double a, b, c;
};
int n;
vector<node> v(15, {0, 0, 0});
double fun(double time) {
    double hap = 0;
    for (int j =1; j<=n; j++) {
        hap=max(hap,v[j].a*(time-v[j].b)*(time-v[j].b)+v[j].c);
    }
    return hap;
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i].a>>v[i].b>>v[i].c;
    double l = 0, r = 300;
    while (r - l > 1e-9) {
        double m1=l+(r-l)/3;
        double m2=r-(r-l)/3;
        if (fun(m1)<fun(m2)) {
            r=m2;
        } else {
            l=m1;
        }
    }
    cout<<fixed<<setprecision(18)<<min(fun(l), fun(r))<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
