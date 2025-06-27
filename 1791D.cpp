#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//#define int long long
#define MOD 1000000007
#define INF 1e18
#define fl(i,n) for(int i=0;i<n;i++)
#define sz(v) sort(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
#define nnia(n,v) int n; cin >> n; vector<int> v(n);for(int i=0;i<n;i++) cin >> v[i];
#define nna(n,v2) vector<int> v2(n);for(int i=0;i<n;i++) cin >> v2[i];
#define nni(x) int x; cin >> x;

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
template <class T> void _print(multiset <T> v) {
    cerr << "[ "; for (T i : v) {
        _print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {
    cerr << "[ "; for (auto i : v) {
        _print(i); cerr << " ";} cerr << "]";}
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

    int t;
    cin >> t;
    while(t--){
        int n;string s; cin >> n >> s;
        vector<int> v1(26,0), v2(26,0);
        for(auto i:s){
            v1[i-'a']++;
        }
        int maxi = 0;
        for(auto i:s){
            int a = --v1[i-'a'];
            int b = ++v2[i-'a'];
            int sum = 0;
            for(int i = 0;i<v2.size();i++){
                if(v1[i] !=0)  sum++;
                if(v2[i] !=0) sum++;
            }
            maxi = max(maxi,sum);
        }
        cout << maxi << endl;
    }

    
    // nni(t);
    // while(t--){
    //     int n;
    //     cin >> n;
    //     string s;
    //     cin >> s;
    //     map<char,int> mpp;
    //     for(auto i:s){
    //         mpp[i]++;
    //     }
    //     map<char,int> mpp1;
    //     int j = 0;
    //     int maxi = 0;
    //     while(j<s.size()){
    //         mpp1[s[j]]++;
    //         mpp[s[j]]--;
    //         if(mpp[s[j]] == 0) mpp.erase(s[j]);
    //         int a = mpp.size();
    //         int b = mpp1.size();
    //         myFunc(b,a);
    //         maxi = max(maxi, a+b);
    //         j++;
    //     }
    //     cout << maxi << endl;
    // }
    return 0;
}