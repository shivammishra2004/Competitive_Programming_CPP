#include <bits/stdc++.h>
using namespace std; 

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{"; _print(p.ff); cerr << ", "; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {
        _print(i); cerr << " ";} cerr << "]";}
// template <typename T>
// void myFunc(T&& value) {
//     cerr << value << ' ';
// }
// template <typename T, typename ...Ts>
// void myFunc(T&& value, Ts&& ...rest) {
//     cerr << value << ' ';
//     myFunc(std::forward<Ts>(rest)...);
//     cerr << endl;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> v1;
        vector<int> v2;
        int a;
        int count = n;
        while(n--){
            cin >> a;
            v1.push_back(a);
        }
        n= count;
        int b;
        while(n--){
            cin >> b;
            v2.push_back(b);
        }
        int sum =0,maxi = 0,maxim=0;
        // cout << n << " " << k;
        for(int i=0;i<min(count,k);i++){
            maxim = max(maxim,v2[i]);
            sum += v1[i];
            maxi = max(maxi,sum+maxim*(k-i-1));
        }
        cout << maxi << endl;
        
    }
    
    return 0;
}