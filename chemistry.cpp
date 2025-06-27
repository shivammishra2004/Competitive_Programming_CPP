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

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string str;
        cin >> str;
        set<char> s{str.begin(), str.end()};
        // for(auto i :s) cout << i << " ";
        // cout << endl;
        vector<char> v{s.begin(),s.end()};
        vector<int> freq;
        int count;
        for(int i = 0;i<v.size();i++){
            count = 0;
            for(int j = 0;j<str.size();j++){
                if (v[i] == str[j]){
                    count++;
                }
            }
            freq.push_back(count);
        }
        int odd = 0;
        for(int i = 0;i<freq.size();i++){
            if(freq[i]&1) odd++;
        }
        debug(odd);
        cout << ((odd<=k+1)? "YES" : "NO") << endl;
        // // for(auto i:freq) cout << i << " ";
        // // cout << endl;
        // int odd =0,even = 0,oddone = 0,oddtwo = 0,evenone = 0,eventwo = 0;
        // for(int i = 0;i<freq.size();i++){
        //     if(freq[i]&1){
        //         odd++;
        //         if(freq[i] == 1) oddone++;
        //         else oddtwo++;
        //     }else{
        //         even++;
        //         if(freq[i] == 2) evenone++;
        //         else eventwo++;
        //     }
        // }
        // // cout << odd << even << oddone << oddtwo << endl;
        // while(k--){
        //     if(oddone) odd--,oddone--;
        //     else if(oddtwo) even++,odd--,oddtwo--;
        //     else{
        //         if(evenone) even--,evenone--,oddone++,odd++;
        //         else if(eventwo) even--,eventwo--,oddtwo++,odd++;
        //     }
        // }
        // cout << ((odd<=1)? "YES" : "NO") << endl;
    }
    
    return 0;
}