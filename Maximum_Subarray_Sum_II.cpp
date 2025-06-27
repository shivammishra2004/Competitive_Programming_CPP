#include <bits/stdc++.h>
using namespace std; 

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> v;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    int start = 0;
    int sum = 0;
    int size = 0;
    int fas = INT_MIN;
    int maxi = -449444999;
    for(int i = 0;i<v.size();i++){
        sum+=v[i];
        size = i-start+1;
        maxi = max(maxi,size);
        while(b<size){
            sum-=v[start];
            start++;
        }
    }
    cout << maxi << endl;
    
    return 0;
}