#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010], r[200010], k;
int exgcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
int CRT() {
  int n = 1, ans = 0;
  for (int i = 1; i <= k; i++) n = n * r[i];
  for (int i = 1; i <= k; i++) {
    int m = n / r[i], b, y;
    exgcd(m, r[i], b, y);  // b * m mod r[i] = 1
    ans = (ans + a[i] * m * b % n) % n;
  }
  return (ans % n + n) % n;
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>k;
    for(int i=1;i<=k;i++) cin>>r[i]>>a[i];
    cout<<CRT();
}
