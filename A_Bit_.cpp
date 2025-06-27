#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    int count = 0;
    while(n--){{
        string s;
        cin >> s;
        if (s[1] == '+'){
            count++;
        }else if(s[1] == '-'){
            count--;
        }
    }}
    
    cout << count << endl;
    return 0;
}