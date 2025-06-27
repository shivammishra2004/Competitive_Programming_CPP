#include <bits/stdc++.h>
using namespace std; 

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n;
    cin >> n;
    vector<int> v;
    int a;
    while(cin >> a)v.push_back(a);
    sort(v.begin(),v.end());
    int sum  =0;
    for(auto i:v) sum+=i;
    int sum_last = 0;
    for(int i = v.size()-1;i>=0;i--){
        sum -=v[i];
        sum_last+=v[i];
        if(sum_last > sum){
            cout << v.size()-i;
            break;
        }
    }
    return 0;
}