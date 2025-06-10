#include<bits/stdc++.h>
using namespace std;
struct node{
	int col, x, y, t;
};
queue<node> bfs;
node temp;
int hsh[27], x, y, mx[8], now=0, n, sz[8];
vector<vector<int>> vis(1010, vector<int>(1010, 0));
char a, b, c, d;
bool inrange(int col, int x, int y) {
    if(x>=0&&x<n&&y>=0&&y<n&&(vis[x][y]|col)!=vis[x][y]) return 1;
    return 0;
}
void mix(int col, int x, int y) {
    sz[vis[x][y]]--;
    vis[x][y]|=col;
    sz[vis[x][y]]++;
    bfs.push({vis[x][y], x, y, temp.t+1});
}
void itz() {
	for(int i=1;i<=7;i++) {
        mx[i]=max(mx[i], sz[i]);	
	}
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cerr<<vis[i][j]<<" ";
        }
        cerr<<'\n';
    }
    cerr<<"///////////////////////////";
}
void solve() {
	cin>>n;
	now=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			vis[i][j]=0;
		}
	}  
	for(int i=1;i<=7;i++) mx[i]=0, sz[i]=0;
	for(int i=0;i<3;i++) {
		cin>>a>>x>>y;
		bfs.push({hsh[a-'A'], x, y, 0});
		sz[hsh[a-'A']]++;
	}
    itz();
	while(bfs.size()) {
		temp=bfs.front();
		bfs.pop();
        //cerr<<temp.x<<" "<<temp.y<<" "<<temp.col<<" "<<temp.t<<'\n';
		if(temp.t>now) {
			now=temp.t;
			itz();
		}
		if(inrange(temp.col, temp.x+1, temp.y)) {
            mix(temp.col, temp.x+1, temp.y);
        } 
        if(inrange(temp.col, temp.x-1, temp.y)) {
            mix(temp.col, temp.x-1, temp.y);
        } 
        if(inrange(temp.col, temp.x, temp.y+1)) {
            mix(temp.col, temp.x, temp.y+1);
        } 
        if(inrange(temp.col, temp.x, temp.y-1)) {
            mix(temp.col, temp.x, temp.y-1);
        } 
    }
    cin>>d;
    cout<<mx[hsh[d-'A']]<<"\n";
}
signed main() {
	hsh['Y'-'A']=1;
	hsh['B'-'A']=2;
	hsh['R'-'A']=4;
	hsh['G'-'A']=3;
	hsh['P'-'A']=6;
	hsh['O'-'A']=5;
	hsh['D'-'A']=7;
	int q;
	cin>>q;
	while(q--) solve();
}
