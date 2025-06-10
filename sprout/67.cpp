#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a(100010, 0), b(100010, 0), x(100010, 0), y(100010, 0);
int n, k;
int chk(int day) {
    for(int i=0;i<n;i++) {
        x[i]=a[i]+(day-1)*b[i];
    }
    sort(x.begin(), x.begin()+n-1);
    int ret=0;
    for(int i=0, j=0;i<n&&j<n;i++) {
        if(x[i]>y[j]) ret++, j++;
    }
    return ret;
}
void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<n;i++) cin>>y[i];
    sort(y.begin(), y.begin()+n-1);    
    int l=1, r=1e9, mid;
    if(chk((int)1e9)<=k) {cout<<-1<<'\n';return;}
    while(l<=r) {
        mid=(l+r)>>1;
        if(chk(mid)>=k) r=mid-1;
        else l=mid+1;
    }
    cout<<l-1<<'\n';
}
signed main() {
    int q;
    cin>>q;
    while(q--) solve();
}
