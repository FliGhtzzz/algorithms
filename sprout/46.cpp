#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int l, r, data, fa;
};
int ndc=0, root;
pair<int, int> ans1, ans2;
vector<node> v(100010, {-1, -1, -1, -1});
void dfs3(int val, int now) {
    //cerr<<now<<" "<<ans2<<"haha\n";
    if(ans1.first==abs(v[now].data-val)) ans2={abs(v[now].data-val), v[now].data};
    else if(ans1.first>abs(v[now].data-val)) ans2={-3e9, -3e9}, ans1={abs(v[now].data-val), v[now].data};
    if(v[now].data<val&&v[now].r!=-1) dfs3(val, v[now].r);
    else if(v[now].data>val&&v[now].l!=-1) dfs3(val, v[now].l);
    //cerr<<now<<" "<<ans1<<"hmm\n";
}
void dfs2(int val, int now) {
    if(v[now].data==val) {
        if(v[now].l!=-1) {
            int temp=v[now].l;
            while(v[temp].r!=-1) temp=v[temp].r;
            v[now].data=v[temp].data, v[v[temp].fa].r=v[temp].l;
            if(v[temp].l!=-1) v[v[temp].l].fa=v[temp].fa;
        }
        else if(v[now].r!=-1) {
            int temp=v[now].r;
            while(v[temp].l!=-1) temp=v[temp].l;
            v[now].data=v[temp].data, v[v[temp].fa].l=v[temp].r;
            if(v[temp].r!=-1) v[v[temp].r].fa=v[temp].fa;
        }
        else if(v[now].fa!=-1) {
            if(v[now].data>v[v[now].fa].data) v[v[now].fa].r=-1;
            else v[v[now].fa].l=-1;
        }
    }
    else if(v[now].data>val) dfs2(val, v[now].l);
    else dfs2(val, v[now].r);
}
void dfs1(int id, int now) {
    //cerr<<now<<"hehe\n";
     if(v[now].data>v[id].data) {
        if(v[now].l==-1) v[now].l=id, v[id].fa=now;
        else dfs1(id, v[now].l);
    }
    else {
        if(v[now].r==-1) v[now].r=id, v[id].fa=now;
        else dfs1(id, v[now].r);
    }
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    string a;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a>>b;
        v[i].data=b;
        if(a=="insert") {
            if(ndc==0) root=i, ndc++;
            else {
                dfs1(i, root);
                ndc++;
            }
        }
        else if(a=="delete") {
            dfs2(b, root);
            ndc--;            
        }
        else {
            ans1.first=3e9, ans2.first=-3e9;
            dfs3(b, root);
            cout<<ans1.second;
            if(ans2.first!=-3e9) cout<<" "<<ans2.second;
            cout<<'\n';
        }
    }
}
