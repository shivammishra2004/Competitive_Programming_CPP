#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define int long long
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

int ask(int m1,int m2){
    cout << "? " << m1 << " " << m2 << endl;
    int x;cin  >>x;
    return x;
}

void solve(){
    int hi = 999;
    int lo = 2;
    while(lo<=hi){
        // int m1 = (2*lo + hi)/3;
        // int m2 = (lo + 2*hi)/3;
        int m1 = lo + (hi-lo)/3;
        int m2 = lo+ 2*(hi-lo)/3;
        int x = ask(m1,m2);
        if(x == (m1+1)*(m2+1)) hi = m1-1;
        else if(x == (m1)*(m2+1)){
            lo = m1+1;
            hi = m2-1;
        }else if(x == m1*m2) lo = m2+1;
    }
    cout << "! " << lo << endl;
}
// oid solve(){
//     int high = 999;
//     int low = 0;
//     while(low<high){
//         int mid1 = (high+2*low)/3;
//         int mid2 = (2*high+low)/3;
//         int x = ask(mid1,mid2);
//         if(x == (mid1+1)*(mid2+1)){
//             high = mid1;
//         }else if(x == (mid1)*(mid2+1)){
//             low = mid1+1;
//             high = mid2;
//         }else if(x == mid1*mid2){
//             low = mid2+1;
//         }
//     }
  
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    
    int t;cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}