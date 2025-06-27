#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long
#define ll long long
#define endl "\n"
// #define MOD 1000000007
#define INF 1e18
#define fl(i,n) for(int i=0;i<n;i++)
#define rep(i,x,n) for(int i=x;i<n;i++)
#define sz(v) sort(v.begin(),v.end())
#define all(v) v.begin(),v.end()
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define nnia(n,v) int n; cin >> n; vector<int> v(n);for(int i=0;i<n;i++) cin >> v[i];
#define nna(n,v2) vector<int> v2(n);for(int i=0;i<n;i++) cin >> v2[i];
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
bool isPrime(int n) { if (n <= 1) return false; if (n <= 3) return true; if (n % 2 == 0 || n % 3 == 0) return false; for (int i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0) return false; return true; }
int nCr(int n, int r) { if (r > n - r) r = n - r; int ans = 1; for (int i = 0; i < r; i++) { ans *= (n - i); ans /= (i + 1); } return ans; }
int nCrModP(int n, int r, int p) { if (r > n - r) r = n - r; int C[r + 1]; memset(C, 0, sizeof(C)); C[0] = 1; for (int i = 1; i <= n; i++) { for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p; } return C[r]; }
int nPr(int n, int r) { int ans = 1; for (int i = 0; i < r; i++) ans *= (n - i); return ans; }
int nPrModP(int n, int r, int p) { int ans = 1; for (int i = 0; i < r; i++) ans = (ans * (n - i)) % p; return ans; }
int log(int num , int base) { int ans = 0; while (num) { num /= base; ans++; } return ans; }
int countSetBits(int x) { int ans = 0; while (x) { ans += (x & 1); x >>= 1; } return ans; }

void _print(long long t) { cerr << t; }
//void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{ "; _print(p.first); cerr << ", ";
    _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ ";for (const auto& i : v) {
        cerr << endl << "      ";_print(i.first); cerr << " -> ";
        _print(i.second); cerr << " ";}cerr << endl << "    ]";}
template <class T> void _print(vector<vector<T>> v) {
    cerr << "[\n"; for (const auto& i : v)
        { cerr << "  "; _print(i); cerr << "\n"; } cerr << "]"; }
template <typename T>
void myFunc(T&& value) {
    cerr << value << ' ';
}
template <typename T, typename ...Ts>
void myFunc(T&& value, Ts&& ...rest) {
    cerr << value << ' ';
    myFunc(std::forward<Ts>(rest)...);
    cerr << endl;
}
const int MOD = 998244353;

// Function to compute power of 2 modulo MOD
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Function to compute the modular result without constructing the full binary string
long long computeModBinaryConcat(long long n) {
    long long result = 0;
    long long len = 1; // Binary length starts from 1

    while ((1LL << (len - 1)) <= n) {
        long long start = (1LL << (len - 1));
        long long end = min(n, (1LL << len) - 1);
        long long count = end - start + 1;

        // Sum of numbers in range [start, end]
        long long sum = (count * (start + end) / 2) % MOD;

        // Shift the result by count * len bits and add the sum
        result = (result * modPow(2, count * len, MOD) + sum) % MOD;

        len++;
    }

    return result;
}

// Function to generate the binary concatenated string for a given number n
string generateBinaryString(long long n) {
    string binaryString = "";

    for (long long i = 1; i <= n; ++i) {
        string binary = bitset<64>(i).to_string();           // Get 64-bit binary representation
        binary = binary.substr(binary.find('1'));           // Remove leading zeros
        binaryString += binary;                             // Append to the result
    }

    return binaryString;
}

int32_t main() {
    long long n;
    cout << "Enter n: ";
    cin >> n;

    // Modular result computation
    cout << "Modulo Result: " << computeModBinaryConcat(n) << endl;

    // Binary string generation (useful for testing smaller values of n)
    if (n <= 100) { // Limit to smaller n to avoid memory issues
        string binaryString = generateBinaryString(n);
        cout << "Binary Concatenated String: " << binaryString << endl;

        // If you want to verify, compute its modulo directly
        long long binaryModResult = 0;
        for (char c : binaryString) {
            binaryModResult = (binaryModResult * 2 + (c - '0')) % MOD;
        }
        cout << "Verification Modulo Result: " << binaryModResult << endl;
    }

    return 0;
}
