#include<bits/stdc++.h>
using namespace std;
int cnt=0;
vector<vector<int>> nex(200010, vector<int>(26, 0));
bitset<200010> exist;  // 该结点结尾的字符串是否存在
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
signed main() {
    string s;
    cin>>s;
    insert(s, s.size());
    cout<<fnd(s, s.size());
}