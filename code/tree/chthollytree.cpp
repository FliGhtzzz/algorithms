//珂朵莉樹 AKA 老司機樹 這個使用SET
#include<bits/stdc++.h>
using namespace std;
struct Node_t {
  int l, r;
  mutable int v; //其中，int v 是你自己指定的附加数据。

  Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}

  bool operator<(const Node_t &o) const { return l < o.l; }
};
set<Node_t> odt;
auto split(int x) { //split 操作是珂朵莉树的核心。它接受一个位置 x，将原本包含点 x 的区间（设为 [l, r]）分裂为两个区间 [l, x) 和 [x, r]，并返回指向后者的迭代器。
  auto it = odt.lower_bound(Node_t(x, 0, 0));
  if (it != odt.end() && it->l == x) return it;
  --it;
  int l = it->l, r = it->r, v = it->v;
  odt.erase(it);
  odt.insert(Node_t(l, x - 1, v));
  return odt.insert(Node_t(x, r, v)).first;
}
void assign(int l, int r, int v) { //把[l, r]區間改成v
  auto itr = split(r + 1), itl = split(l);
  odt.erase(itl, itr);
  odt.insert(Node_t(l, r, v));
}
// void perform(int l, int r) {
//   auto itr = split(r + 1), itl = split(l);
//   for (; itl != itr; ++itl) {
//     // Perform Operations here
//   }
// }
signed main() {
    //初始化时，向珂朵莉树中插入一个极长区间（如题目要求维护位置 1 到 n 的信息，插入区间 [1,n+1]）。
}