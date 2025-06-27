#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int r,c;
    cin >> r >> c;
    if(r>=c+18) cout << "RCB" << endl;
    else cout << "CSK" << endl;
    
    return 0;
}