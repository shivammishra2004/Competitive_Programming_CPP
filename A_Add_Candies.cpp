#include <bits/stdc++.h>
using namespace std; 

double positiveRoot(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;
    
    // Assume the discriminant is non-negative for simplicity
    if (discriminant < 0) {
        return 0; // Return a negative value to indicate an error (no real roots)
    }
    
    // Calculate and return the positive root
    return (-b + sqrt(discriminant)) / (2 * a);
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
        int n;
        cin >> n;
        cout << n << endl;
        for(int i = 1; i<=n;i++){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}