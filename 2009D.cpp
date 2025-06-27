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
    
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int N = 1e5+3;
        int ones = 0;
        int zeroes = 0;
        set<int> s1,s2;
        for(int i = 0;i<n;i++){
            int x,y;cin >> x >> y;
            if(y==1){ s2.insert(x);}
            else{ s1.insert(x);}
        }
        int sum1=0,sum2=0;
        int ans = 0;
        for(auto it=s1.begin();it != s1.end();it++){
            if(s2.find(*it)!= s2.end()){
                ans += s1.size() + s2.size() -2;
            }
        }
        for(auto it=s2.begin();it != s2.end();it++){
            if(s1.find(*it-1)!= s1.end() && s1.find(*it+1)  != s1.end()){
                ans++;
            }
        }
        for(auto it=s1.begin();it != s1.end();it++){
            if(s2.find(*it-1)!= s2.end() && s2.find(*it+1) != s2.end()){
                ans++;
            }
        }
        cout << ans << endl;



        // int n;cin >> n;
        // vector<pair<int,int>> v(n);
        // fl(i,n){
        //     int x,y;cin >> x >> y;
        //     v[i] = {x,y};
        // }
        // sort(v.begin(),v.end());
        // debug(v);
        // vector<pair<int,int>> pfs(n);
        // int sum1=0,sum2=0;
        // for(int i = 0;i< n;i++){
        //     if(v[i].second == 0){
        //         sum1++;
        //     }else if(v[i].second == 1){
        //         sum2++;
        //     }
        //     pfs[i] = {sum1,sum2};
        // }
        // debug(pfs);
        // int ans = 0;
        // for(int i = 0;i<n;i++){
        //     if(v[i].second == 0 && i<n-1 && v[i+1].second == 1){
        //         debug(pfs.back().first - pfs[i].first);
        //         ans += pfs.back().first - pfs[i].first;
        //     }else if(v[i].second == 1 && i>0 && v[i-1].second == 0){
        //         debug(pfs.back().second - pfs[i].second);
        //         ans += pfs.back().second - pfs[i].second;
        //     }
        // }
        // for(int i = 1;i<n-2;i++){
        //     if(v[i].second = 0 && v[i-1].first == v[i+2].first -2) ans++;
        // }
        // for(int i = 2;i<n-1;i++){
        //     if(v[i].second == 1 && v[i-2].first == v[i+1].first -2) ans++;
        // }
        // debug(ans);
        // cout << ans << endl;
    }
    
    return 0;
}