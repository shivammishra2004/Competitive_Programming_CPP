#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,t;
    cin >> n >> t;
    if(n ==1 && t == 10) cout << -1;
    else{
        cout << t;
        int i = 1;
        if(t==10) i++;
        for(i;i<n;i++){
            cout << 0;
        }
    }
    
    return 0;
}