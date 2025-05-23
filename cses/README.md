I will ut the *AC-code* of all cses problems I have solved and my methods of solving them here.
Will be presented in the following form `(sort by the task number)`
```cpp
//question number
/*
My metheds and opinions of soving this problems 
*/
//AC-code
```
EX:
```cpp
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
```

[My cses profile](https://cses.fi/user/318680)