#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int a,b,n;
    cin >> a >> b >> n;
    bool flag = false;
    for(int i = 0;i<=9;i++){
        if((10*a+i )% b == 0){
            cout << a << i;
            flag = true;
            break;
        }
    }
    if(flag){
        n--;
        while(n--){
            cout << 0;
        }
    }else{
        cout << -1;
    }
    
    return 0;
}