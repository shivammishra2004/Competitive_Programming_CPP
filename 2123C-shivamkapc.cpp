#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int maxi = *max_element(a.begin(), a.end());
        int mini = *min_element(a.begin(), a.end());
        
        vector<int> pref_min(n), suff_max(n);
        
        // Calculate prefix minimums
        pref_min[0] = a[0];
        for (int i = 1; i < n; i++) {
            pref_min[i] = min(pref_min[i-1], a[i]);
        }
        
        // Calculate suffix maximums
        suff_max[n-1] = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            suff_max[i] = max(suff_max[i+1], a[i]);
        }
        
        string result = "";
        
        for (int i = 0; i < n; i++) {
            if (a[i] == maxi || a[i] == mini) {
                result += "1";
            } else if (pref_min[i] == a[i] && suff_max[i] == a[i]) {
                result += "1";
            } else {
                result += "0";
            }
        }
        
        cout << result << "\n";
    }
    
    return 0;
}hoasdfasdfasdfdfadfa sdf 