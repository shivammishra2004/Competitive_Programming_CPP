#include <bits/stdc++.h>
using namespace std; 

int findIndex(vector<int>& arr, int target) {
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == target){
            return i+1;
        }
    }
    return 0;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    vector<int> v;
    int a,n;
    cin >> a;
    while(cin >> n){
        v.push_back(n);
    }
    for(int i = 1;i<=v.size();i++){
        cout << findIndex(v,i) << " ";
    }
    cout << endl;
    // for(auto i:v) cout << i << " ";
    return 0;
}