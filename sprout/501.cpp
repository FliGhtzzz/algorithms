#include<bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int arr[200010], i=3;
    arr[1]=3, arr[2]=1, arr[3]=2;
    for(;i<=n;i<<=1) {
        for(int j=1;j<=i;j++) {
            arr[i+j]=arr[j]*2;
            arr[j]=arr[j]*2-1;
        }
    }
    for(int j=1;j<=i;j++) if(arr[j]<=n) cout<<arr[j]<<" ";
}
