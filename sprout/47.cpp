#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void write(int x){
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
    return;
}
struct node{
    int l, r, data;
};
vector<node> v(2010, {-1, -1, -1});
void dfs1(int now, int id) {
    if(v[now].data>v[id].data) {
        if(v[now].l==-1) v[now].l=id;
        else dfs1(v[now].l, id);
    }
    else {
        if(v[now].r==-1) v[now].r=id;
        else dfs1(v[now].r, id);
    }
}
void dfs2(int id) {
    if(v[id].l!=-1) dfs2(v[id].l);
    if(v[id].r!=-1) dfs2(v[id].r);
    write(v[id].data);
    cout<<'\n';
}
signed main() {
    int n;
    n=read();
    for(int i=1;i<=n;i++) {
        v[i].data=read();
    }
    for(int i=2, temp=0;i<=n;i++) {
        dfs1(1, i);
    }
    dfs2(1);
    //for(int i=1;i<=n;i++) cerr<<v[i].l<<" "<<v[i].r<<" "<<v[i].data<<'\n';
}

