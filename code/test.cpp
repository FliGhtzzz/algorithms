#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ans[n+1];
    int route[n+1];
    int spot[n+1];
    queue<int> cnt;
    vector<int> fnlans;
    int a,b;
    for(int i=1;i<=n;i++){
        spot[i]=0;
        route[i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ans[a].push_back(b);
        ans[b].push_back(a);
    }
        cnt.push(1);
        route[1]=1;
        spot[1]=1;
    while(cnt.size()!=0){
        int x=cnt.front();cnt.pop();
        for(int i:ans[x]){
            if(spot[i]!=1){
            cnt.push(i);
            route[i]=x;
            spot[i]=1;
            }
        }
    }
    if(route[n]==0) cout<<"IMPOSSIBLE";
    else{
        int M=n;
        while(M!=1){
        fnlans.push_back(M);
        M=route[M];
        }
    
    fnlans.push_back(1);
    reverse(fnlans.begin(),fnlans.end());
    cout<<fnlans.size()<<'\n';
    for(int i:fnlans) cout<<i<<" ";
    }
}