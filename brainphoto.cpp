#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,m;
    cin >> n >> m;
    char a;
    while(cin >> a){
        if(a == 'C' || a == 'M' || a == 'Y'){
            cout << "#Color";
            return 0;
        }
    }
    cout << "#Black&White";
    
    return 0;
}