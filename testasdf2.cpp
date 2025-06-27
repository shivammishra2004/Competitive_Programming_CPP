#include <iostream>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long result = (a ^ b) + (b ^ c) + (a ^ c);
    cout << c <<  " " <<result << endl;
}

int main() {
    int t;cin >> t;
    while(t--)solve();
    return 0;
}


