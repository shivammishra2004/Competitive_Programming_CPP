#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    if(n==2) cout << "NO" << endl;
    else if(n&1) cout <<"NO" << endl;
    else cout << "YES" << endl;
    return 0;
}