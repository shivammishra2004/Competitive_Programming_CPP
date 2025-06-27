#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string a,b;
    cin >> a >> b;
    if (a == b) cout << -1 << endl;
    else cout << max(a.size(),b.size());
    
    return 0;
}