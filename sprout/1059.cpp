#include<bits/stdc++.h>
   using namespace std;
#define int long long
int nums[1010], n;
int maxScore() {
       vector<vector<int>> dp(1010, vector<int>(1010, 0));
       for (int i = 0; i < n; i++) {
           dp[i][i] = nums[i];
       }
       for (int len = 2; len <= n; len++) {
           for (int i = 0; i <= n - len; i++) {
               int j = i + len - 1;
               int take_left = nums[i] - dp[i+1][j];
               int take_right = nums[j] - dp[i][j-1];
               dp[i][j] = max(take_left, take_right);
           }
       }
       int total = 0;
       for (int num : nums) {
           total += num;
       }
       return (total + dp[0][n-1]) / 2;
   }
   
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
       cin >> nums[i];
   }
   cout << maxScore(); 
}
 
