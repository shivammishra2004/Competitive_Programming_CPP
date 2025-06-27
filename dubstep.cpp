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
#define debug(x) cout << #x <<" "; _print(x); cout << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cout << t;}
void _print(int t) {cout << t;}
void _print(string t) {cout << t;}
void _print(char t) {cout << t;}
void _print(lld t) {cout << t;}
void _print(double t) {cout << t;}
void _print(ull t) {cout << t;}

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
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    string s;
    cin >> s;
    string newstr = "";
    debug(s);
    for(int i =0;i<s.size();i++){
        if(s[i] == 'W'){
            // debug(s[i]);
            i++;
            if(s[i] == 'U'){
                debug(s[i+1]);
                i++;
                if(s[i] == 'B'){
                    i++;
                    continue;
                }else{
                    newstr.push_back(s[i-2]);
                    newstr.push_back(s[i-1]);
                    newstr.push_back(s[i]);
                }
            }else{
                newstr.push_back(s[i-1]);
                newstr.push_back(s[i]);
            }
        }else{
            debug(s[i]);
            newstr.push_back(s[i]);
        }
    }
    debug(newstr);
    return 0;
}