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
        int x,y,r;
        cin >> x >> y >> r;
        int ate;
        ate = r/30 + x;
        cout << (int)ceil((double)ate / y) << endl;
    }
    
    return 0;
}