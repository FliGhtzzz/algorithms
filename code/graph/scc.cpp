#include <iostream>
#include <vector>
#include <stack>
using namespace std;
  
int n, m, a, b, dfn[100005], stk[100005], low[100005], pa[100005], scc, idx;
vector <int> v[100005];
stack <int> st;
  
void tarjan(int x){
    idx++;
    dfn[x] = low[x] = idx;
    st.push(x);
    stk[x] = 1;
    for (auto i:v[x]){
        if (!dfn[i]){
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if (stk[i]){
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (dfn[x] == low[x]){
        scc++;
        pa[x] = scc;
        int nxt = -1;
        while (nxt != x){
            nxt = st.top();
            st.pop();
            pa[nxt] = scc;
            stk[nxt] = 0;
        }
    }
}
  
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        if (!dfn[i]) tarjan(i);
    }
    if (scc == 1){
        cout << "YES\n";
    }
    else{
        for (int i = 1; i <= n; i++){
            for (int j:v[i]){
                if (pa[i] != pa[j]){
                    cout << "NO\n";
                    cout << j << " " << i << "\n";
                    return 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if(pa[i]!=pa[1]) {
                cout << "NO\n";
                    cout << 1 << " " << i << "\n";
                    return 0;
            }
        }
    }
}