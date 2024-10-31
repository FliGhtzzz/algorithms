#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
//Using gp_hash_table can search the prefix sum of pos in O(loglogn) update in O(loglogMAXN)
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> order_set;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<int, int, custom_hash> bit;
signed up(int pos, int val) {
    for(int i=pos;i<=200000000+10;i+=i&-i) {
        bit[i]+=val;
    }
    return 0;
}
signed search(int pos) {
    if(pos<=0) return 0;
    int ret=0;
    for(int i=pos; i>0 ;i-=i&-i) {
        if(bit.find(i)!=bit.end()) {
            ret+=bit[i];
        }
    }
    return ret;
}
   