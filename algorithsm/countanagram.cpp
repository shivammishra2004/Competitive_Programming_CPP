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

map<char, int> stringToMap(string& s) {
    map<char, int> m;
    for (char c : s) m[c]++;
    return m;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1,s2;
    cin >> s1 >> s2;
    map<char,int> mpp2;
    for(char c:s2) mpp2[c]++;
    int i = 0,j=0;
    int count = mpp2.size();
    // map<char,int> mpp1;
    int k = s2.size();
    int ans = 0;
    while(j<s1.size()){
        mpp2[s1[j]]--;
        if(mpp2[s1[j]] == 0){
            count--;
        }
        int a = j-i+1;
        if(a<k){
            j++;
        }else if (a==k){
            if(count == 0){
                ans++;
            }
            mpp2[s1[i]]++;
            // debug(mpp2[s1[i]]);
            if(mpp2[s1[i]] ==1) count++;
            // debug(count);
            i++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}