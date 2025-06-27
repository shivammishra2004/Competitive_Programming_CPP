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
        int a,b,c;
        cin >> a>> b >> c;
        if((a+b+c)%2 != 0){
            cout << -1 << endl;
            continue;
        }
        while(c>a+b){
            c-=2;
        }
        cout << (c+b+a)/2<< endl;
    }
    
    return 0;
}