#include<bits/stdc++.h>
using namespace std;
int v[7], ans=0, a[4]={9, 5, 3, 1};
void solve() {
    ans=0;
    for(int i=1;i<=6;i++) cin>>v[i];
    ans+=v[6]+v[5]+v[4]+v[3]/4;
    v[3]%=4;
    v[1]=max(0, v[1]-v[5]*11);
    if(v[4]*5>=v[2]) v[1]=max(0, v[1]-(v[4]*20-v[2]*4)), v[2]=0;
    else v[2]-=v[4]*5;
    if(v[3]) {
        if(v[2]>=a[v[3]]) v[2]-=a[v[3]], v[1]=max(0, v[1]-(36-v[3]*9-a[v[3]]*4));
        else v[2]=0, v[1]=max(0, v[1]-(36-v[3]*9-a[v[3]]*4));
    ans++;
    }
    ans+=v[2]/9;
    v[2]%=9;
    ans+=(int)(v[2]>=1);
    v[1]=max(0, v[1]-(36-v[2]*4));
    ans+=v[1]/36+(int)((v[1]%36)>=1);
    cout<<ans<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;
    cin>>q;
    while(q--) solve();
}
