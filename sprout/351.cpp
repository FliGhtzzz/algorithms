#include<bits/stdc++.h>
using namespace std;
signed main() {
    int n, INF=1e9;
    cin>>n;
    int dis[105][105], mx=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>dis[i][j];
            if(dis[i][j]==-1) dis[i][j]=INF;
        }
    
    }
    cout<<"0\n";
    for(int i=2;i<=n;i++) {
        bool imp=0;
        for(int j=1;j<i;j++) {
            //if(dis[i][j]==-1) dis[i][j]=INF;
            //if(dis[j][i]==-1) dis[j][i]=INF;
            for(int k=1;k<i;k++) {
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                dis[j][i]=min(dis[j][i],dis[j][k]+dis[k][i]);
            }
            if(dis[i][j]==INF) imp=1;
            else mx=max(mx, dis[i][j]);
            if(dis[j][i]==INF) imp=1;
            else mx=max(mx, dis[j][i]);
            cerr<<i<<" "<<j<<" "<<dis[i][j]<<" "<<dis[j][i]<<'\n';
        }
        if(imp) cout<<"-1\n";
        else cout<<mx<<'\n';
    }
}
