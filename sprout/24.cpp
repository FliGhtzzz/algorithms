#include<bits/stdc++.h>
using namespace std;
struct node {
    int fr, ba;
}sh[101], id[1000010];
signed main() { 
    int n, m, a, b;
    for(int i=1;i<=100;i++) sh[i].fr=-1, sh[i].ba=-1;
    string s;
    cin>>n>>m;
    while(m--) {
        cin>>s;
        if(s=="ADD") {
            cin>>a>>b;
            if(sh[a].fr==-1) {
                sh[a].fr=b, sh[a].ba=b;
            }
            else id[sh[a].ba].ba=b, id[b].fr=sh[a].ba, sh[a].ba=b;
        }
        else if(s=="JOIN") {
            cin>>a>>b;
            int i=sh[a].fr;
            if(i==-1) continue;
            if(sh[b].fr==-1) {sh[b].fr=sh[a].fr, sh[b].ba=sh[a].ba, sh[a].fr=-1, sh[a].ba=-1;}
            else id[sh[a].fr].fr=sh[b].ba, id[sh[b].ba].ba=sh[a].fr, sh[a].fr=-1, sh[b].ba=sh[a].ba, sh[a].ba=-1;
        }
        else {
            cin>>a;
            if(sh[a].fr==-1) cout<<"queue "<<a<<" is empty!\n";
            else if(sh[a].fr!=sh[a].ba) sh[a].fr=id[sh[a].fr].ba;
            else sh[a].fr=-1, sh[a].ba=-1;
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<"queue "<<i<<":";
        if(sh[i].fr==-1) cout<<" empty";
        else {
            int j=sh[i].fr;
            while(j!=sh[i].ba) {cout<<" "<<j;j=id[j].ba;}
            cout<<" "<<sh[i].ba;
        }
        cout<<"\n"[i==n];
    }
}
