#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val;       // 區間總和 (可以改成 max/min/xor)
    Node *lc, *rc; // 左右子樹指標
    Node(int v=0, Node* l=nullptr, Node* r=nullptr) : val(v), lc(l), rc(r) {}
};

const int L = 0, R = 1000000; 
// 假設值域是 [0, 1e6)；如果需要更大值域，可以改成 1e9 或動態指定

// 建立一個空樹 (所有值都為 0)
Node* build(int l=L, int r=R) {
    return new Node(0, nullptr, nullptr);
}

// ***持久化單點修改***
// pos: 要修改的位置
// new_val: 設置的新值
Node* modify(Node* cur, int pos, int new_val, int l=L, int r=R) {
    Node* node = new Node(*cur); // copy 當前節點（舊節點保留）
    if (l + 1 == r) {
        node->val = new_val;
        return node;
    }
    int mid = (l + r) >> 1;
    if (pos < mid) {
        if (!node->lc) node->lc = new Node();
        node->lc = modify(node->lc, pos, new_val, l, mid);
    } else {
        if (!node->rc) node->rc = new Node();
        node->rc = modify(node->rc, pos, new_val, mid, r);
    }
    node->val = 0;
    if (node->lc) node->val += node->lc->val;
    if (node->rc) node->val += node->rc->val;
    return node;
}

// 區間查詢
int query(Node* cur, int ql, int qr, int l=L, int r=R) {
    if (!cur || qr <= l || r <= ql) return 0;    // 不相交
    if (ql <= l && r <= qr) return cur->val;     // 完全覆蓋
    int mid = (l + r) >> 1;
    return query(cur->lc, ql, qr, l, mid) + query(cur->rc, ql, qr, mid, r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<Node*> version; 
    version.push_back(build()); // v[0]: 初始空樹 (全 0)

    // v[1]: 設 index 2 = 5
    version.push_back(modify(version.back(), 2, 5));

    // v[2]: 設 index 5 = 7
    version.push_back(modify(version.back(), 5, 7));

    // v[3]: 設 index 2 = 9 (覆蓋舊值)
    version.push_back(modify(version.back(), 2, 9));

    cout << "v[1] sum[0,10) = " << query(version[1], 0, 10) << "\n"; // 5
    cout << "v[2] sum[0,10) = " << query(version[2], 0, 10) << "\n"; // 5+7=12
    cout << "v[3] sum[0,10) = " << query(version[3], 0, 10) << "\n"; // 9+7=16

    cout << "回到舊版本 v[1] sum[0,10) = " << query(version[1], 0, 10) << "\n"; // 5
}
