#include <bits/stdc++.h>
using namespace std;

vector<bool> primes(1e6+7, true);

void generatePrimes(){
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= 1e6; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j <= 1e6; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    generatePrimes();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int ans = 0;

        // Finding the smallest prime factor of n which is <= k
        for (int i = 2; i <= 1e6; i++) {
            if (primes[i] && n % i == 0 && n / i <= k) {
                ans = i;
                break;
            }
        }
        int x = n;
        int power = 2;
        while(n/ pow(ans,power) <= k){
            power++;
        }
        ans = pow(ans,power);

        if (k >= n) 
            cout << 1 << endl;
        else if (ans == 0) 
            cout << n << endl;
        else 
            cout << ans << endl;
    }

    return 0;
}
