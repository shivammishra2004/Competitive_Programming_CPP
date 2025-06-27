#include <bits/stdc++.h>
using namespace std; 

int adjDiff(vector<int>& arr){
    int first = arr[0] - 0;
    for(int i = 1;i<arr.size();i++){
        int e = arr[i]-arr[i-1];
        if(e>first){
            first = e;
        }
    }
    


    return first;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
            int n,x;
    cin >> n >> x;
    vector<int> v;
    int a;
    while(n--){
        cin >> a;
        v.push_back(a);
    }
    int d = adjDiff(v);
    cout << max(d,(x-v.back())*2) << endl;
    }
    return 0;
}