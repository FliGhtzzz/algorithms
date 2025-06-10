#include<bits/stdc++.h>
using namespace std;
#define int long long
int arr[1000010], ans=0, mod=10000019;
void solve(int l, int r) {
    if(l==r) return;
    int mid=(l+r)>>1;
    solve(l, mid);
    solve(mid+1, r);
    int temp[r-l+2], lc=l, rc=mid+1, lp=0, rp=0, i=1;
    for(;i<=r-l+1;i++) {
        if(rp==r-mid) {
            for(;i<=r-l+1;i++) temp[i]=arr[lc], ans=(ans+arr[lc++]*rp)%mod;
            break;
        }
        if(lp==mid-l+1) {
            for(;i<=r-l+1;i++) temp[i]=arr[rc++];
            break;
        }
        if(arr[lc]>arr[rc]) {
            temp[i]=arr[rc];
            ans=(ans+arr[rc++]*(mid-l+1-lp))%mod;
            rp++;
        }
        else {
            temp[i]=arr[lc];
            ans=(ans+arr[lc++]*rp)%mod;
            lp++;
        }
    }
    for(int i=1;i<=r-l+1;i++) arr[l+i-1]=temp[i];
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    solve(1, n);
    cout<<ans;
}
