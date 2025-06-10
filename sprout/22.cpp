#include "lib0022.h"
#include<bits/stdc++.h>
using namespace std;
void solve(int N, int order[]) {
    int n=N;
    stack<int> a, b;
    for(int i=1;i<=n;i++) {
        push_train();
        a.push(i);    
    }
    for(int i=0;i<n;i++) {
        while(a.top()!=order[i]) {
            b.push(a.top());
            a.pop();
            move_station_1_to_2();
        }
        a.pop();
        move_station_1_to_2();
        pop_train();
        while(b.size()) {
            a.push(b.top());
            b.pop();
            move_station_2_to_1();
        }
    }
}
