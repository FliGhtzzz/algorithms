//Weird Algorithm-1068
/*using while() to detect if n is 1 or not, still need to prevent n overflow if u r trying to use int*/
#include<bits/stdc++.h>
using namespace std;
signed main() {
    long long x;
    cin>>x;
    cout<<x<<" ";
    while(x>1) {
        if(x&1) x=3*x+1;
        else x/=2;
        cout<<x<<" ";
    }
    return 0;
}