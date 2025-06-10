#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q, b;
    string a;
    multiset<int> s, t;
    cin>>q;
    while(q--) {
        cin>>a>>b;
        if(a=="insert") {
            s.insert(b);
            t.insert(-b);
        }
        else if(a=="delete") {
            s.erase(s.find(b));
            t.erase(t.find(-b));
        }
        else {
            auto big=s.lower_bound(b);
            auto small=t.lower_bound(-b);
            if(small!=t.end()) {
                if(b==-*small) cout<<b<<'\n';
                else if(big!=s.end()) {
                    if(*big-b==b+*small) cout<<-*small<<" "<<*big<<'\n';
                    else if(*big-b>b+*small) cout<<-*small<<'\n';
                    else cout<<*big<<'\n';
                }
                else cout<<-*small<<'\n';
            }
            else cout<<*big<<'\n';
        }
    }
}
