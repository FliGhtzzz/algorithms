#include<bits/stdc++.h>
using namespace std;
struct node {
    int f, ba;
};
vector<int>  l(1000010, -1), now(1000010, -1), o(1000010, 0);
vector<node> arr(1000010, {0, 0});
void solve() {
    string a;
    int n, k, temp, q, b, cnt=0;
    cin>>n;
    arr[0].ba=1000010, arr[1000010].f=0;
    for(int i=1;i<=n;i++) {
        cin>>k;
        for(int j=1;j<=k;j++, cnt++) {
            cin>>temp;
            l[temp]=i;
            o[cnt]=temp;
        }
    }
    cin>>q;
    int last=0;
    while(q--) {
        cin>>a;
        if(a=="ENQUEUE") {
            cin>>b;
            if(l[b]!=-1) {
                if(now[l[b]]!=-1) {
                    arr[arr[now[l[b]]].ba].f=b;
                    int t=arr[now[l[b]]].ba;
                    arr[now[l[b]]].ba=b;
                    arr[b].f=now[l[b]];
                    arr[b].ba=t;
                    now[l[b]]=b;
                }
                else {
                    now[l[b]]=b;
                    arr[b].ba=arr[last].ba;
                    arr[b].f=last;
                    arr[arr[last].ba].f=b;
                    arr[last].ba=b;
                    last=b;
                }
            }
            else {
                    now[l[b]]=b;
                    arr[b].ba=arr[last].ba;
                    arr[b].f=last;
                    arr[arr[last].ba].f=b;
                    arr[last].ba=b;
                    last=b;
            }
        }
        else {
            cout<<arr[0].ba<<'\n';
            if(l[arr[0].ba]!=-1) {
                if(now[l[arr[0].ba]]==arr[0].ba) now[l[arr[0].ba]]=-1;
            }
            //cerr<<arr[arr[0].ba].ba<<"******\n";
            //cerr<<"temmie owo\n";
            arr[0].ba=arr[arr[0].ba].ba;
            arr[arr[0].ba].f=0;
            //cerr<<"owoovo\n";
            //if(q==0) return;
        }
    }
    for(int i=0;i<cnt;i++) l[o[i]]=-1;
    //cerr<<"baocoder\n";
    return;
}
signed main() {
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) {
        cout<<"Line #"<<i<<'\n';
        solve();
    }
    //cerr<<"pudding114541\n";
    return 0;
}
