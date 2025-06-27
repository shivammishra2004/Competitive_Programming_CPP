#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    int y = n;
    vector<int> v;
    while(y!=0){
        int x;
        cin >> x;
        v.push_back(x);
        // cout << x << y << endl;
        if(x==y){
            // sort(v.begin(),v.end());
            // while(v.back() == y){
            //     cout << v.back() << " ";
            //     v.pop_back();
            //     y--;
            //     if(y == 0) return 0;
            // }
            
        }
        cout << endl;
    }
    return 0;
}