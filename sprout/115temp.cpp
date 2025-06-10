#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 10000019;
int arr[1000010];
int temp[1000010];
int ans = 0;
void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            ans += (arr[i] + arr[j]) * (mid - i + 1);
            ans %= MOD;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int p = l; p <= r; ++p)
        arr[p] = temp[p];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(0, n - 1);
    cout << ans % MOD << '\n';
}
