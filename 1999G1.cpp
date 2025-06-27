#include <bits/stdc++.h>
using namespace std;

#define int long long

int ask(int a,int b){
    cout << "? " <<a << " " << b << endl;
    int x;cin >> x;
    return x;
}

void solve(){
    int lo = 2;
    int hi = 999;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int x = ask(mid,mid);
        if(x != mid*mid) hi = mid-1;
        else lo = mid+1;
    }
    cout << "! " << lo << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    
    int t;cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}