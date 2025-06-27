#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--){
        long long n, k,x;
        cin >> n >> k >> x;
        if(x<(k*(k+1)/2) || x>(k*(2*n-k+1)/2)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    
    return 0;
}