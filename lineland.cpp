#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int a;
    int mina;
    vector<int> v;
    int n;
    cin >> n;
    while(cin >> a){
        v.push_back(a);
    }
    for(int i = 0;i<v.size();i++){
        if (i == 0) cout<< v[1]-v[0];
        else if (i == v.size()-1) cout << v[n-1] - v[n-2];
        else{
            mina = min(v[i]-v[i-1],v[i+1]-v[i]);
            cout << mina << " ";
        }
        cout << " " << max(v[n-1]-v[i],v[i]-v[0]) << endl;
    }
    
    return 0;
}