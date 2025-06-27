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
        double x;
        cin >> x;
        string s = "123456789";
        double n = (-1 + sqrt(361-8*x))/2;

        int m = ceil(n);
        string ans = s.substr(m,s.length());
        int car = x - (45 - m*(m+1)/2);
        string answer = "";
        if (car != 0){
            answer = std::to_string(car);
        }

        cout << answer << ans << endl;
    }
    return 0;
}