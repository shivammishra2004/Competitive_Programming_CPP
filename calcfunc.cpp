#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // int t;
    // cin >> t;
    // while(t--){
        long long n;
        cin >> n;
        if(n&1) cout << -(n+1)/2 << endl;
        else cout << n/2 << endl;
    // }
    
    return 0;
}