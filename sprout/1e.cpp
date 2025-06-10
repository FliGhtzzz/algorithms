#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int x, y;
};
int dist(node x, node y) {
    return (x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y);
}
node a[500010], b[500010];
void solve() {
    int n, m, ta, tb;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>ta>>tb;
        a[i]={ta, tb};
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        cin>>ta>>tb;
        b[i]={ta, tb};
    }
    for(int i=1, j=m;i<=n;i++) {
        while(dist(a[i], b[j])<dist(a[i], b[max((int)1, j-1)])) {
            j=max((int)1,j-1);
        }
        cout<<dist(a[i], b[j])<<" ";
    }
    cout<<'\n';
     for(int i=1, j=n;i<=m;i++) {
        while(dist(b[i], a[j])<dist(b[i], a[max((int)1, j-1)])) {
            j=max((int)1,j-1);
        }
        cout<<dist(b[i], a[j])<<" ";
    }
    cout<<'\n';
}


signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}
