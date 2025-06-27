// __builtin_popcount(x) returns popcount of a number 
// __builtin_ctz(x) return trailing zeros ( 10000 returns 4);
// to get the position of most significant bit(1-indexed from left) (32-__builtin_clz(12)) = 4
// to get the total number of bits like for 12 we can also use __lg(12) to get 4



#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
    
    // cout << __builtin_clz(12) << endl;
    cout << __builtin_ctz(12) << endl;
    return 0;
}