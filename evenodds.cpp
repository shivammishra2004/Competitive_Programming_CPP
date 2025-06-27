#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    long long k;
    double n;
    cin >> n >> k;
    long long position = ceil(n/2);
    if (position >=k) cout << 2*k-1;
    else cout << 2*(k-position);
    return 0;
}