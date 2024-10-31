#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
vector<int> arr(MAXN, 0);
vector<int> tree(4*MAXN, 0);
void build(int l, int r, int id=1) {
    if(l==r) {
            tree[id]=a[l];
            return;
    }
    int m=(l+r)/2;
    build(l, m, id*2);
    build(m+1, r, id*2+1);
    tree[id]=tree[id*2]+tree[id*2+1]; 
}
long long query1(long long ql, long long qr, long long l, long long r, long long id = 1) {
    if (qr < l || ql > r) return 0;
    if (ql <= l && r <= qr) return tree[id];
    long long m = (l + r) / 2;
    return query1(ql, qr, l, m, id * 2)+query1(ql, qr, m + 1, r, id * 2 + 1);
}
void update(int pos, int val, int l, int r, int id=1) {
    if(l == r) {
        tree[id] = val;
        return;
    }
    int m = (l+r)/2;
    if(pos <= m)
        update(pos, val, l, m, id*2);
    else
        update(pos, val, m+1, r, id*2+1);
    tree[id] = tree[id*2] + tree[id*2+1];
}
signed main() {
        int n, m, sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) {
                cin>>a[i];
        }
        build(1, n);
        cout<<query1(2, 4, 1, 4)<<'\n';
        update(2, 5 , 1, n);
        for(int i=1;i<20;i++) cerr<<tree[i]<<" ";
        cout<<query1(2, 4, 1, 4);
        return 0;
}