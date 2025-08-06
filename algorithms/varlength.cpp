#include <bits/stdc++.h>
using namespace std; 

int smallestsum(vector<int> v,int k){
    int start = 0;
    int minSize = INT_MAX;
    int sum =0;
    for(int i =0;i<v.size();i++){
        sum+=v[i];
        while(sum>=k){
            minSize = min(minSize,i-start+1);
            sum-=v[start];
            start++;
        }
        if(minSize == 1) break;
    }
    return minSize;
}

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
        int n,k;
        cin >> n >> k;
        vector<int> v;
        int a;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        cout << smallestsum(v,k);
    }
    
    return 0;
}