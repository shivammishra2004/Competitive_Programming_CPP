#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int count1= 0,count0 = 0;
        char rem = '0';
        if (s[0] == '0') rem = '1';
        int i = 0;
        while(i <s.size()){
            while(s[i] == s[0]){
                i++;
            }
            // cout << i << endl;
            count1++;
            if(i==n){
                break;
            }
            while(s[i]== rem){
                i++;
            }
            // cout << i << endl;
            count0++;

        }
            cout << min(count0,count1) << endl;

    }
    
    return 0;
}