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
        int n,m,k,H,ans= 0;
        cin >> n >> m >> k >> H;
        for(int i=0;i<n;i++){
            int h;
            cin >> h;
            m--;
            if(h<=H-m*k || h>=H+m*k){
                ans++;
            }
        cout << ans << endl;
        }
        cout << ans << endl;
    }
        return 0;
}