#include <bits/stdc++.h>
using namespace std;
long long n, mod = 1e9 + 7;

void m(long long f[2][2], long long s[2][2]) {
    long long temp[2][2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                temp[i][j] += f[i][k] * s[k][j];
                temp[i][j] %= mod;
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            f[i][j] = temp[i][j];
        }
    }
}
 
long long me() {
    long long s[2][2] = {{1, 1}, {1, 0}};
    long long ret[2][2] = {{1, 0}, {0, 1}};
    
    while (n) {
        if (n & 1) m(ret, s);
        m(s, s);
        n >>= 1;
    }
    return ret[0][0];
}
 
int main() {
    cin >> n;
    if (n == 0) {
        cout << 0;
    } else {
        --n;
        cout << me();
    }
    return 0;
}
 