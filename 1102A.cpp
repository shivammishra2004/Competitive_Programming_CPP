#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int n;
    cin >> n;
    if(n%3 == 1 || n%4 == 1){
        cout << 1;
    }else{
        cout << 0;
    }
    
    return 0;
}