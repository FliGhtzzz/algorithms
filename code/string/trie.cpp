#include<bits/stdc++.h>
using namespace std;
int cnt=0, i=1, q, nex[1000010][26];
bitset<100010> exist;  // 该结点结尾的字符串是否存在
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
    fill(nex[0],nex[0]+1000010*26, 0);
    exist.reset();
    int n;
    cnt=0;
    string s;
    cin>>n;
    while(n--) {
        cin>>s;
        insert(s, s.size());
    }
    cout<<"Case #"<<i<<": "<<cnt<<'\n';
}
signed main() {
    cin>>q;
    for(;i<=q;i++);
}