#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        // Count 1's
        int m = 0;
        for(char c: s)
            if(c == '1') 
                ++m;

        if(m <= k) {
            cout << "Alice\n";
            continue;
        }
        if(k >= n/2+1) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}
