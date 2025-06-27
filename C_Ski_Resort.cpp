#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 1e18
#define int long long
#define fl(i,n) for(int i=0;i<n;i++)
#define sz(v) sort(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())

void _print(long long t) { cerr << t; }
// void _print(int t) { cerr << t; }
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
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {
        _print(i); cerr << " ";} cerr << "]";}

int somefunc(int i, int j) {
    int n = i - j + 1;
    if (n <= 0) {
        return 0;
    }
    return n * (n + 1) / 2;
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
        int n,k,q;
        cin >> n >> k >> q;
        vector<int> v;
        int a;
        int count = 0;
        int sum = 0;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        debug(v);
        vector<int> v1;
        bool flag = true;
        for(int i = 0;i<v.size();i++){
            if(v[i] <=q){
                count++;
            }else if (v[i] >q){
                sum+= somefunc(count,k);
                count = 0;
            }
            debug(count);
        }
        debug(count);
        sum+= somefunc(count,k);
        cout << sum << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// #ifndef ONLINE_JUDGE
// #define debug_multi(...) cerr << "[" << #__VA_ARGS__ << "]: "; _print_debug(__VA_ARGS__); cerr << endl;
// #else
// #define debug_multi(...)
// #endif

// #define MOD 1000000007
// #define int long long
// #define INF 1e18
// #define fl(i,n) for(int i=0;i<n;i++)
// #define sz(v) sort(v.begin(),v.end())
// #define srt(v) sort(v.begin(),v.end())
// #define mxe(v) *max_element(v.begin(),v.end())
// #define mne(v) *min_element(v.begin(),v.end())

// void _print(long long t) { cerr << t; }
// // void _print(int t) { cerr << t; }
// void _print(string t) { cerr << t; }
// void _print(char t) { cerr << t; }
// void _print(long double t) { cerr << t; }
// void _print(double t) { cerr << t; }
// void _print(unsigned long long t) { cerr << t; }
// void _print_debug() { cerr << ""; }

// template <class T, class V> void _print(pair <T, V> p) {
//     cerr << "{ "; _print(p.first); cerr << ", ";
//     _print(p.second); cerr << "}";}
// template <class T> void _print(vector <T> v) {
//     cerr << "[ "; for (T i : v) {
//         _print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {
//     cerr << "[ "; for (T i : v) {
//         _print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {
//     cerr << "[ "; for (T i : v) {
//         _print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {
//     cerr << "[ "; for (auto i : v) {
//         _print(i); cerr << " ";} cerr << "]";}
// template<typename T, typename... Args>
// void _print_debug(T var1, Args... var2) {
//     cerr << var1 << " ";
//     _print_debug(var2...);
// }

// int somefunc(int i, int j) {
//     int n = i - j + 1;
//     if (n <= 0) {
//         return 0;
//     }
//     return n * (n + 1) / 2;
// }

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
    
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k,q;
//         cin >> n >> k >> q;
//         vector<int> v;
//         int a;
//         while(cin >> a ){
            
//             v.push_back(a);
//         }
//         vector<int> v1;
//         for(int i = 0;i<v.size();i++){
//             if(v[i] >q) v1.push_back(i);
//         }

//         // cout << endl;
//         // cout << v1[0] << " " << somefunc(v1[0],k) << endl;
//         int sum = 0;
//         if(v1.size()>0){
//             sum += somefunc(v1[0],k);
//             for(int i = 1;i<v1.size()-1;i++){
//                 sum +=somefunc(v1[i+1]-v1[i]-1,k);
//             }
//             sum+= somefunc(v.size()-v1.back()-1,k);
//         // cout << sum << endl;
//         }else sum+= somefunc(v.size(),k);

//         cout << sum << endl;
//     }
    
//     return 0;
// }