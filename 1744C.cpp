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

// int binarySearch(const std::vector<int>& arr, int target) {
//     int low = 0;
//     int high = arr.size() - 1;
//     int result = -1;  // Use -1 to indicate that no such element was found

//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] > target) {
//             result = arr[mid];
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     return result;
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif

    int t; cin >> t;
    while(t--){
        int n;char c;string s; cin >> n >> c >> s;
        int next(0);
        int count =0;
        for(int i =0;i<s.size();i++){
            if(s[i] == 'g') break;
            count++;
        }
        if(c == 'g'){
            cout << 0 << endl;
            continue;
        }
        next = n+count;
        // debug(next);
        int maxi = 0;
        for(int i = n-1;i>=0;i--){
            if(s[i] == 'g') next = i;
            else if(s[i] == c){
                maxi = max(maxi, next-i);
            }
        }
        cout << maxi << endl;
        
    }
    
    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;
    //     char ch;
    //     cin >> ch;
    //     string s;
    //     cin >> s;
    //     vector<int> a;
    //     vector<int> b;
    //     for(int i = 0;i<s.size();i++){
    //         if(s[i] == 'g') a.push_back(i);
    //         else if(s[i] == ch) b.push_back(i);
    //     }
    //     // debug(a);
    //     // debug(b)
    //     int maxi = 0;
    //     if(b.empty() || ch == 'g'){
    //         cout << 0 << endl; 
    //         continue;
    //     }
    //     else if(a.back() < b.back()) maxi = s.size()-binarySearch(b,a.back())+a[0];
    //     // debug(maxi);
    //     int i = 0,j=0;
    //     while(a[i]<=a.back()){
    //         if(j <b.size() && a[i] >b[j]){
    //             maxi = max(maxi,a[i]-b[j]);
    //             // debug(maxi);
    //             j++;
    //         }
    //         else i++;
    //     }
    //     // cerr << endl;
    //     cout << maxi << endl;
    // }
    
    return 0;
}