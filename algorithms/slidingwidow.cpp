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

int maxsumSubarray(vector<int> v,int k){
    int maxi = INT_MIN;
    int sum = 0;
    // for(int i = 0;i<v.size();i++){
    //     sum+=v[i];
    //     if(i>=k-1){
    //         maxi = max(maxi,sum);
    //         sum -= v[i-(k-1)];
    //     }
    // }
    int i = 0,j=0;
    // while(j<v.size()){
    //     int a = j-i+1;
    //     //operation.
    //     sum +=v[j];
    //     if(a < k){
    //     }else if (a ==k ){
    //         //calculation
    //         maxi = max(maxi,sum);
    //         // now maintain window.
    //         sum -=v[i];
    //         // reverse operation
    //         i++;
    //     }
            // j++;
    // }
    while(j<v.size()){
        sum+=v[j];
        if(j-i+1==k){
            // debug(sum);
            maxi = max(sum,maxi);
            sum-=v[i];
            i++;
        }
        j++;
    }
    return maxi;

}

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
        vector<int> v;
        int a;
        while(n--){
            cin >> a;
            v.push_back(a);
        }
        cout << maxsumSubarray(v,k) << endl;
        for(int i = 0;i<=v.size()-3;i++){
        //     int x = v[i] +v[i+1]+v[i+2];
        //     if((x) > max) max = x;
        // }
        // cout << max << endl;
    }
    int t=5;
    
    return 0;
}