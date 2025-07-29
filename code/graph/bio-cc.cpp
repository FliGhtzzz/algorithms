#include <bits/stdc++.h>
using namespace std;

struct BCC {
    int n, timer;
    vector<vector<int>> G;
    vector<int> dfn, low;
    vector<vector<int>> bcc;
    stack<pair<int,int>> stk;
    vector<bool> inBCC;    // 標記哪些點出現在 BCC 中
    vector<char> vis;      // 用於 extractBCC，避免 sort/unique

    BCC(int _n): n(_n), timer(0) {
        G.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        inBCC.assign(n, false);
        vis.assign(n, 0);
    }

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void dfs(int u, int parent) {
        dfn[u] = low[u] = ++timer;

        for (int v : G[u]) {
            if (!dfn[v]) {
                stk.emplace(u, v);      // 樹邊
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] >= dfn[u]) { // u 是關節點
                    extractBCC(u, v);
                }
            } else if (v != parent && dfn[v] < dfn[u]) {
                stk.emplace(u, v);      // 回邊
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    void extractBCC(int u, int v) {
        vector<int> comp;
        while (!stk.empty()) {
            auto [x, y] = stk.top(); stk.pop();
            if (!vis[x]) { vis[x] = true; comp.push_back(x); }
            if (!vis[y]) { vis[y] = true; comp.push_back(y); }
            if (x == u && y == v) break;
        }
        if (!comp.empty()) {
            for (int node : comp) {
                inBCC[node] = true;
                vis[node] = false;  // reset for下一次 BCC 使用
            }
            bcc.push_back(comp);
        }
    }

    void get_bcc() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i, -1);
                if (!stk.empty()) {
                    vector<int> comp;
                    while (!stk.empty()) {
                        auto [x, y] = stk.top(); stk.pop();
                        if (!vis[x]) { vis[x] = true; comp.push_back(x); }
                        if (!vis[y]) { vis[y] = true; comp.push_back(y); }
                    }
                    if (!comp.empty()) {
                        for (int node : comp) {
                            inBCC[node] = true;
                            vis[node] = false;
                        }
                        bcc.push_back(comp);
                    }
                }
            }
        }

        // 單獨出現的點（沒在任何 BCC 中）
        for (int i = 0; i < n; i++) {
            if (!inBCC[i]) {
                bcc.push_back({i});
            }
        }
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    BCC solver(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        solver.add_edge(a, b);
    }

    solver.get_bcc();

    cout << solver.bcc.size() << "\n";
    for (auto &comp : solver.bcc) {
        cout << comp.size();
        for (int v : comp) cout << " " << v;
        cout << "\n";
    }
}
