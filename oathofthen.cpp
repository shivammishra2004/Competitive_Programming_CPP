#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    vector<int> a;
    int min = INT_MAX,max = INT_MIN;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        if(x<min) min = x;
        if(x>max) max = x;
        a.push_back(x);
    }
    int count = 0;
    for(auto i:a){
        if(i<max && i>min)count++;
    }
    cout << count;
    return 0;
}