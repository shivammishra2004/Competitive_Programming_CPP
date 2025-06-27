#include <bits/stdc++.h>
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
#define MOD 1000000007
#define INF 1e18
#define int long long
#define fl(i,n) for(int i=0;i<n;i++)
#define sz(v) sort(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define mxe(v) *max_element(v.begin(),v.end())
#define mne(v) *min_element(v.begin(),v.end())
 
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
 
template <class T, class V> void _print(pair <T, V> p) {
    cerr << "{ "; _print(p.first); cerr << ", ";
    _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {
    cerr << "[ "; for (auto& i : v) {
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

int getSecondMin(const std::vector<int>& vec) {
    if (vec.size() < 2) {
        throw std::invalid_argument("Vector must contain at least two elements.");
    }

    int min1 = std::numeric_limits<int>::max();
    int min2 = std::numeric_limits<int>::max();

    for (const int& num : vec) {
        if (num <= min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2 && num != min1) {
            min2 = num;
        }
    }

    // Check if all elements are equal
    if (min2 == std::numeric_limits<int>::max()) {
        return min1;
    }

    return min2;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> vec;
        while(n--){
            int j;
            cin >> j;
            int a;
            vector<int> v;
            while(j--){
                cin >> a;
                v.push_back(a);
            }
            debug(v);
            int min = mne(v);
            int secMin = getSecondMin(v);
            vec.emplace_back(min,secMin);
        }

    std::sort(vec.begin(), vec.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first; // Sort descending based on first elements if second elements are equal
        }
        return a.second < b.second; // Sort ascending based on second elements
    });
        // cout << vec[0].first << " ";
        debug(vec);
        int min_first = vec[0].first;
        for(int i = 1;i<vec.size();i++){
            if(vec[i].first<min_first){
                min_first= vec[i].first;
            }
        }
        vec[0].second = min_first;
        int beauty = 0;
        for(auto i:vec){
            beauty += i.second;
        }
        cout << beauty << endl;
    }
    
    return 0;
}