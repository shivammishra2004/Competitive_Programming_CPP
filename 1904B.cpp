#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

//#define int long long
#define nnn(n) int n; cin >> n; vector<int> v(n);for(int i=0;i<n;i++) cin >> v[i];
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

int findLastOccurrence(const vector<pair<int, int>>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;  // Initialize result to -1 to indicate the target is not found initially.

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid].first == target) {
            result = mid;  // Update result because we found the target.
            left = mid + 1;  // Move to the right half to find the last occurrence.
        }
        else if (arr[mid].first < target) {
            left = mid + 1;  // Move to the right half.
        }
        else {
            right = mid - 1;  // Move to the left half.
        }
    }

    return result;
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
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        vector<pair<int,int>> p;
        int j = 0;
        for(auto i:v){
            p.emplace_back(i,j);
            j++;
        }
        sort(p.begin(),p.end());
        int index = 0;
        int lastIndex = 0,sum=0;
        // cout << findLastOccurrence(p,p[0].first) << endl;
        vector<pair<int,int>> p2;
        while(index<p.size()){
            int key = p[index].first;
            index = findLastOccurrence(p,key)+1;
            int count =index-lastIndex;
            // debug(count);
            sum +=count;
            p2.emplace_back(key,sum);
            lastIndex = index;
        }
        index = 0,sum=0;
        int count = 0;
        int lastp = 0;
        int bus = 0;
        for(int i = 0;i<p2.size();i++){
            count = p2[i].second-lastp;
            sum +=p2[i].first*count;
            int j = i;
            bus +=count;
            debug(sum);
            while(sum>=p2[i+1].first){
                i++;
                sum =p2[i].first*p2[i].second-lastp;
                lastp = p2[i].second;
                bus++;
            }
            i = j;
            lastp = p2[i].second;
            debug(sum);
            debug(bus);
        }
        // debug(p);
    }
    
    return 0;
}