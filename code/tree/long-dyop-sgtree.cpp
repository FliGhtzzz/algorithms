#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val;
    Node *lc, *rc;
    Node(int v=0, Node* l=nullptr, Node* r=nullptr) : val(v), lc(l), rc(r) {}
};

// *** 持久化單點修改 ***
// cur: 舊版本的根 (可為 nullptr)
// pos: 修改的位置
// new_val: 新值 (這裡是「直接設值」, 也可改成加值)
// L, R: 當前節點所表示的範圍
Node* modify(Node* cur, int L, int R, int pos, int new_val) {
    Node* node = new Node();        // 建立新節點
    if (cur) *node = *cur;          // 如果有舊節點，複製內容 (Persistent!)
    if (L + 1 == R) {
        node->val = new_val;        // 到達葉節點
        return node;
    }
    int mid = (L + R) >> 1;
    if (pos < mid) {
        node->lc = modify(cur ? cur->lc : nullptr, L, mid, pos, new_val);
    } else {
        node->rc = modify(cur ? cur->rc : nullptr, mid, R, pos, new_val);
    }
    node->val = 0;
    if (node->lc) node->val += node->lc->val;
    if (node->rc) node->val += node->rc->val;
    return node;
}

// *** 區間查詢 ***
int query(Node* cur, int L, int R, int ql, int qr) {
    if (!cur || qr <= L || R <= ql) return 0;    // 空節點 or 無交集
    if (ql <= L && R <= qr) return cur->val;     // 完全覆蓋
    int mid = (L + R) >> 1;
    return query(cur->lc, L, mid, ql, qr) + query(cur->rc, mid, R, ql, qr);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int RANGE_L = 0;
    const int RANGE_R = 1e9+1; // [0, 1e9)

    vector<Node*> version;
    version.push_back(nullptr); // v[0] = 空樹 (nullptr)

    // v[1]: 設 index 2 = 5
    version.push_back(modify(version.back(), RANGE_L, RANGE_R, 2, 5));

    // v[2]: 設 index 5 = 7
    version.push_back(modify(version.back(), RANGE_L, RANGE_R, 5, 7));

    // v[3]: 設 index 2 = 9 (覆蓋舊值)
    version.push_back(modify(version.back(), RANGE_L, RANGE_R, 2, 9));

    cout << "v[1] query [0,10) = " << query(version[1], RANGE_L, RANGE_R, 0, 10) << "\n"; // 5
    cout << "v[2] query [0,10) = " << query(version[2], RANGE_L, RANGE_R, 0, 10) << "\n"; // 5+7=12
    cout << "v[3] query [0,10) = " << query(version[3], RANGE_L, RANGE_R, 0, 10) << "\n"; // 9+7=16

    // 舊版本仍可查
    cout << "回到舊版本 v[1] query [0,10) = " << query(version[1], RANGE_L, RANGE_R, 0, 10) << "\n"; // 5
}
