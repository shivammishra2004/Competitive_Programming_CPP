#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long
#define ll long long
#define MOD 1000000007
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
vector<bool> primes(1e6+7,1);
vector<int> allprimes;
void generatePrimes(){
    int n = 1e6+5;
    primes[0] = primes[1] = false;
    for(int i = 2;i*i<n;i++){
        if(primes[i]){
            allprimes.push_back(i);
            for(int j=2*i;j<n;j+=i){
                primes[j] = false;
            }
        }
    }
        for (int i = sqrt(n); i < n; i++) {
        if (primes[i]) {
            allprimes.push_back(i);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    generatePrimes();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int prev = n;
        bool flag = false;

        
    //     for(int i = 2;i*i<=n;i++){
    //         if(n%i == 0){
    //             n/=i;
    //             for(int j = i+1;j*j<=n;j++){
    //                 if(j != i){
    //                     n/=j;
    //                     if(n != i && n!= j){
    //                         if(n*i*j == prev){
    //                             flag = true;
    //                             cout <<"YES" << endl;
    //                             cout << i << " " << j << " " << n << endl;
    //                         }
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // if(!flag) cout << "NO" << endl;


        int b = 1;
        int a = 1;
        for(int i = 2;i*i<=n;i++){
            if(n%i == 0){
                debug(n);
                a = i;
                break;
            }
        }
        int rem = n/a;
        for(int i = a+1;i*i <= rem;i++){
            if(rem%i == 0){
                b = i;
                debug(i);
                break;
            }
        }
        debug(a);
        debug(b);
        if(a != 1 && b != 1 && rem/(b) != a && rem/(b) != b){
            cout << "Yes" << endl;
            cout << a << " " << b << " " << rem/b << endl;
            flag = true;
        }
        if(!flag) cout << "NO" << endl;

    }


    //     vector<int> factor;
    //     int i = 0;
    //     while(n > 1 && i < allprimes.size()) {
    //         while(n % allprimes[i] == 0) {
    //             factor.push_back(allprimes[i]);
    //             n /= allprimes[i];
    //         }
    //         i++;
    //     }
    //     if (n > 1) {
    //         factor.push_back(n);
    //     }
    //     debug(factor);

    //     set<int> s{factor.begin(), factor.end()};
        
    //     if (factor.size() >= 6) {
    //         cout << "YES" << endl;
    //         cout << factor[0] << " " << factor[1] * factor[2] << " ";
    //         int product = 1;
    //         for (int i = 3; i < factor.size(); i++) {
    //             product *= factor[i];
    //         }
    //         cout << product << endl;
    //     } else if (factor.size() >= 4 && s.size() >= 2) {
    //         cout << "YES" << endl;
    //         auto it = s.begin();
    //         int x = *it++;
    //         int y = *it;
    //         cout << x << " " << y << " ";
    //         int product = 1;
    //         for (int f : factor) {
    //             product *= f;
    //         }
    //         product /= (x * y);
    //         cout << product << endl;
    //     } else if (factor.size() >= 3 && s.size() >= 3) {
    //         cout << "YES" << endl;
    //         auto it = s.begin();
    //         int x = *it++;
    //         int y = *it++;
    //         int z = *it;
    //         cout << x << " " << y << " " << z << endl;
    //     } else {
    //         cout << "NO" << endl;
    //     }
    // }
    
    return 0;
}