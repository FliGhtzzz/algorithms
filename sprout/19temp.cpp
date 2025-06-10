#include<bits/stdc++.h>
using namespace std;
struct node {
    int fr, ba;
};
node now[1000010];
int l[1000010], o[1000010], k[1010];
void solve() {
    string s;
    int n, kk, cnt=0, q, b, temp;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>kk;
        for(int j=1;j<=kk;j++) {
            cin>>temp;
            l[temp]=i;
            o[cnt++]=temp;
        }
    }
    int last=0;
    now[0].ba=1000000, now[1000000].fr=0;
    cin>>q;
    while(q--) {
        cin>>s;
        if(s=="ENQUEUE") {
            cin>>b;
            if(l[b]!=-1) {
                if(k[l[b]]!=-1) {
                    cerr<<k[l[b]]<<'\n';
                    now[b].ba=now[k[l[b]]].ba;
                    now[b].fr=k[l[b]];
                    now[now[k[l[b]]].ba].fr=b;
                    now[k[l[b]]].ba=b;
                    k[l[b]]=b;
                    if(now[b].fr==last) last=b;
                    //cerr<<"HI";
                }
                else {
                    k[l[b]]=b;
                    now[now[last].ba].fr=b;
                    now[b].ba=now[last].ba;
                    now[b].fr=last;
                    now[last].ba=b;
                    last=b;
                    //cerr<<"HELLO"<<now[b].fr<<" "<<now[b].ba;
                    //cerr<<now[0].ba<<" "<<now[1000000].fr<<" ";
                }

            }
            else {
                now[now[last].ba].fr=b;
                now[b].ba=now[last].ba;
                now[b].fr=last;
                now[last].ba=b;
                last=b;
            }
        }
        else {
            cout<<now[0].ba<<'\n';
            if(l[now[0].ba]!=-1&&k[l[now[0].ba]]==now[0].ba) k[l[now[0].ba]]=-1;
            if(last==now[0].ba) last=now[now[0].ba].ba;
            now[now[now[0].ba].ba].fr=0;
            now[0].ba=now[now[0].ba].ba;
            //cerr<<"HIPPO";
        }
        /*for(int i=0, cnt=0;i!=1000000&&cnt<10;i=now[i].ba, cnt++) cerr<<now[i].ba<<" ";
        cerr<<'\n';*/
    }
    for(int i=0;i<cnt;i++) l[o[i]]=-1, k[i]=-1;
}
signed main() {
    int q;
    cin>>q;
    for(int i=0;i<=1000000;i++) l[i]=-1;
    for(int i=0;i<1010;i++) k[i]=-1;
    for(int i=1;i<=q;i++) {
        cout<<"Line #"<<i<<'\n';
        solve();
    }
}
