#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long
#define ll long long
#define endl "\n"
#define MOD 1000000007
#define INF 1e18
#define fl(i, n) for(int i = 0; i < n; i++)
#define rep(i, x, n) for(int i = x; i < n; i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define srt(v) sort(v.begin(), v.end())
#define mxe(v) *max_element(v.begin(), v.end())
#define mne(v) *min_element(v.begin(), v.end())
#define nnia(n, v) int n; cin >> n; vector<int> v(n); for (int i = 0; i < n; i++) cin >> v[i];
#define nna(n, v2) vector<int> v2(n); for (int i = 0; i < n; i++) cin >> v2[i];
#define nni(x) int x; cin >> x;

int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }
int power(int a, int b, int m) { int ans = 1; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }
int lcm(int a, int b) { return (a * b) / gcd(a, b); }
int customCeil(int a, int b) { return (a + b - 1) / b; }
int modInverse(int a, int m) { return power(a, m - 2, m); }
int modAdd(int a, int b, int m) { return ((a % m) + (b % m)) % m; }
int modMul(int a, int b, int m) { return ((a % m) * (b % m)) % m; }
int modSub(int a, int b, int m) { return ((a % m) - (b % m) + m) % m; }
int modDiv(int a, int b, int m) { return (modMul(a, modInverse(b, m), m) + m) % m; }
bool isPrime(int n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (int i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
int nCr(int n, int r) { if (r > n - r) r = n - r; int ans = 1; for (int i = 0; i < r; i++) { ans *= (n - i); ans /= (i + 1); } return ans; }
int nCrModP(int n, int r, int p) { if (r > n - r) r = n - r; int C[r + 1]; memset(C, 0, sizeof(C)); C[0] = 1; for (int i = 1; i <= n; i++) { for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p; } return C[r]; }
int nPr(int n, int r) { int ans = 1; for (int i = 0; i < r; i++) ans *= (n - i); return ans; }
int nPrModP(int n, int r, int p) { int ans = 1; for (int i = 0; i < r; i++) ans = (ans * (n - i)) % p; return ans; }
int log(int num, int base) { int ans = 0; while (num) { num /= base; ans++; } return ans; }
int countSetBits(int x) { int ans = 0; while (x) { ans += (x & 1); x >>= 1; } return ans; }

void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{ "; _print(p.first); cerr << ", ";
    _print(p.second); cerr << " }";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";
    } cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";
    } cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (const auto& i : v) {
        cerr << endl << "      "; _print(i.first); cerr << " -> ";
        _print(i.second); cerr << " ";
    } cerr << endl << "    ]";
}
// int recur(int n,int sum,int idx,vector<int>&v){
//     if(idx<n){
//         if(sum == 0) return 1;
//     }
//     if(idx>n) return 0;
//     int a = 0;
//     for(int i = idx;i<n&& sum >=v[i];i++){
//         a+= recur(n,sum-v[i],i,v);
//     }
//     return a;
// }

vector<vector<int>> dp;

int recur(int n, int sum, int idx, vector<int>& v) {
    if (sum == 0) return 1;
    if (idx >= n || sum < 0) return 0;
    
    if (dp[sum][idx] != -1) return dp[sum][idx];
    
    int a = 0;
    a = (a + recur(n, sum - v[idx], idx, v)) % MOD;
    a = (a + recur(n, sum, idx + 1, v)) % MOD;
    
    return dp[sum][idx] = a;
}

//? recur solution doesn't work.

// int iter(int n, int sum, int idx, vector<int>& v) {
//     dp.resize(sum + 1, vector<int>(n + 1, 0));

//     for (int j = 0; j < n; j++) {
//         dp[0][j] = 1;
//     }

//     for (int i = 1; i <= sum; i++) {
//         for (int j = n - 1; j >= 0; j--) {
//             int pick = 0, notpick = 0;

//             if (i >= v[j]) {
//                 pick = dp[i - v[j]][j];
//             }

//             if (j < n - 1) {
//                 notpick = dp[i][j + 1];
//             }

//             dp[i][j] = (pick + notpick) % MOD;
//         }
//     }
//     return dp[sum][n - 1];
// }

//? For some reason iter with sum,idx doesn't work
int iter(int n,int sum,int idx,vector<int>&v){
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    for(int i = 0;i<n;i++){
        dp[i][0] = 1;
    }
    for(int i = n-1; i >= 0; i--) {
        for(int j = 1; j <= sum; j++) {
            dp[i][j] = 0;
            int pick =0,skip = 0;

            if(j >= v[i]) {
                pick = dp[i][j-v[i]];
            }
            if(i+1 <n) skip = dp[i+1][j];
            dp[i][j] = (skip+ pick)%MOD;
        }
    }
    return dp[0][sum];
}

//? this one work,but gives tle when submitted like this, it work if submitted in a simple template.



void solve() {
    int n, sum;
    cin >> n >> sum;
    // dp.resize(n+1,vector<int> (sum+1,-1));
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    cout <<iter(n, sum, 0, v) << endl;
    // cout << recur(n, sum, 0, v) << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}