#include <bits/stdc++.h>
using namespace std; 

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

#define MOD 1000000007
#define INF 1e18
#define fl(i,n) for(int i=0;i<n;i++)
#define sz(v) sort(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())

void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    // int t;
    // cin >> t;
    // vector<vector<int>> vv;
    // while(t--){
    //     int n;cin >>n;
    //     vector<int> v;
    //     while(n--){
    //         int a;cin >>a;
    //         v.push_back(a);
    //     }
    //     vv.push_back(v);
    // }
    // return 0;
    // // for(auto i:vv){
    // //     for(auto j:v){
    // //         cout << j << " ";
    // //     }
    // //     cout << endl;
    // // }
    // cout << endl;

    int n;cin >> n;
    map<int,string> mpp;
    while(n--){
        int a;string s; cin >> a >>s;
        mpp[a] = s;
        // mpp.insert({s,a});
    }
    mpp.erase(mpp.begin(),mpp.find(2));
    debug(mpp);
    // string s; cin >> s
    // map<char,int> mpp;
    // for(auto &i:s){
    //     mpp[i]++;
    // }
    // debug(mpp);


    return 0;
}