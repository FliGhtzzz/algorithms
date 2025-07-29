#include<bits/stdc++.h>
using namespace std;
#define int long long

struct Node {
    int val = 0;
    int L, R;
    Node* lc = nullptr;
    Node* rc = nullptr;

    Node(int ll, int rr) : L(ll), R(rr) {}

    void pull() {
        val = 0;
        if (lc) val += lc->val;
        if (rc) val += rc->val;
    }

    // 單點修改（設值）
    void modify(int pos, int new_val) {
        if (L + 1 == R) {
            val = new_val;
            return;
        }
        int mid = (L + R) >> 1;
        if (pos < mid) {
            if (!lc) lc = new Node(L, mid);
            lc->modify(pos, new_val);
        } else {
            if (!rc) rc = new Node(mid, R);
            rc->modify(pos, new_val);
        }
        pull();
    }

    // 區間查詢
    int query(int ql, int qr) {
        if (qr <= L || R <= ql) return 0;       // 完全不重疊
        if (ql <= L && R <= qr) return val;     // 完全包含
        int mid = (L + R) >> 1;
        int res = 0;
        if (lc) res += lc->query(ql, qr);
        if (rc) res += rc->query(ql, qr);
        return res;
    }

    // 單點加值
    void add(int pos, int delta) {
        if (L + 1 == R) {
            val += delta;
            return;
        }
        int mid = (L + R) >> 1;
        if (pos < mid) {
            if (!lc) lc = new Node(L, mid);
            lc->add(pos, delta);
        } else {
            if (!rc) rc = new Node(mid, R);
            rc->add(pos, delta);
        }
        pull();
    }
};

signed main() {
    Node root(0, 1e9+5); // 假設值域是 [0, 1e9)
    root.modify(5, 10);  // 設 index 5 = 10
    root.add(5, 5);      // index 5 += 5 → 變成 15
    root.modify(100, 7); // 設 index 100 = 7
    cout << root.query(0, 10) << "\n"; // 查詢 [0,10) → 15
    cout << root.query(50, 200) << "\n"; // 查詢 [50,200) → 7
}
