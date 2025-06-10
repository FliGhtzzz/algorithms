#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, t;
    stack<int> s;
    cin>>n;
    while(n--) {
        cin>>t;
        if(t<0&&s.size()) {
            if(s.top()==-t) s.pop();
            else {cout<<"lose light light";return 0;} 
        }
        else s.push(t);
    }
    if(s.size()) cout<<"lose light light";
    else cout<<"weed";
}
