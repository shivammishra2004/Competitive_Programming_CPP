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
        int n;
        cin >> n;
        vector<int> a;
        while(n--){
            int x;
            cin >> x;
            a.push_back(x);
        }
        cout << ((a[0]==*min_element(a.begin(),a.end()))? "YES" : "NO") << endl;
    }
    
    return 0;
}