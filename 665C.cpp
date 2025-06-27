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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    
    // string a;cin >> a;
    // if(a.size() !=1){
    //         for(int i = 0;i<a.size()-1;i++){
    //             if(i== a.size()-2){
    //                 if(a[i] == a[i+1]){
    //                     if(a[i+1] == 'z')a[i+1] = 'a';
    //                     else a[i+1] = 'z';
    //                 }
    //             }
    //             else if(a[i] == a[i+1]){
    //                 if(a[i+2]== 'z' && a[i] == 'a' || a[i+2] == 'a' && a[i] == 'z') a[i+1] = 'b';
    //                 else if(a[i+2] == 'z') a[i+1] = 'a';
    //                 else if(a[i] == 'z') a[i+1] = 'a';
    //                 else a[i+1] = 'z';
    //             }
    //         }
    //     }
    //     if (a.size() != 1) {
    //     for (int i = 0; i < a.size() - 1; i++) {
    //         if (a[i] == a[i + 1]) {
    //             if (i + 2 < a.size() && (a[i + 2] == 'z' && a[i] == 'a' || a[i + 2] == 'a' && a[i] == 'z')) {
    //                 a[i + 1] = 'b';
    //             } else if (i + 2 < a.size() && a[i + 2] == 'z') {
    //                 a[i + 1] = 'a';
    //             } else if (a[i] == 'z') {
    //                 a[i + 1] = 'a';
    //             } else {
    //                 a[i + 1] = 'z';
    //             }
    //         }
    //     }
    // }
    string s;
    cin>>s;
    // char a = a;
    // char b = b;
    // char c = c; 
    int n = s.length();
    for(int i = 1;i<n;i++){
        if(s[i]==s[i-1]){
            if('a'!=s[i] and 'a'!=s[i+1]) s[i]='a';
            else if('b'!=s[i] and 'b'!=s[i+1]) s[i]='b';
            else if('c'!=s[i] and 'c'!=s[i+1]) s[i]='c';
        }
    }
    cout<<s;

    // cout << a << endl;
    return 0;
}