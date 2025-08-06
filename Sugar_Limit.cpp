#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector < int > a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int curr = 0, ans = 0;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i] = {a[i],b[i]};
        sort(v.begin(),v.end(),[](auto i,auto j){
            return i.second < j.second;
        });
        for(int i=0;i<n;i++){
            curr += max(v[i].first,0);
            ans = max(ans,curr-v[i].second);
        }
        cout << ans<< endl;
    }


}