#include<bits/stdc++.h>
using namespace std;
int cnt=0, i=1, q;
vector<vector<int>> nex(1000010, vector<int>(26, 0));
bitset<1000010> exist;  // 该结点结尾的字符串是否存在
  void insert(string s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = true;
  }

  bool fnd(string s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return exist[p];
  }
void solve() {
    for (auto &row : nex) fill(row.begin(), row.end(), 0);
    exist.reset();
    int n, ans=0, temp=0;
    cnt=0;
    string s;
    cin>>n;
    while(n--) {
        int temp=cnt;
        cin>>s;
        insert(s, s.size());
        ans+=min(s.size(), s.size()-(cnt-temp)+1);
        //cerr<<cnt<<" "<<ans<<'\n';
    }
    cout<<"Case #"<<i<<": "<<ans<<'\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>q;
    for(;i<=q;i++) solve();
}
