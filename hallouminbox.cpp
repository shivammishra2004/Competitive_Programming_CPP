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
        int n,k;
        cin >> n >> k;
        vector<int> arr;
        int i = 0;
        int a;
        while(n--){
            cin >> a;
            arr.push_back(a);
            i++;
        }
        if(is_sorted(arr.begin(), arr.end()) || k>1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}