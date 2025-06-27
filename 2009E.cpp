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

int func(int mid,int n,int k){
	int sum1 = ((mid)*(mid+1))/2;
	sum1 -= ((k-1)*k)/2;
	int sum2 = ((n+k-1)*(n+k))/2;
	sum2-= ((mid)*(mid+1))/2;
	return abs(sum1-sum2);
}

int func2(int mid,int n,int k){
    int sum1 = ((mid)*(mid+1))/2;
	sum1 -= ((k-1)*k)/2;
	int sum2 = ((n+k-1)*(n+k))/2;
	sum2-= ((mid)*(mid+1))/2;
	return sum1-sum2;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    int t;
    cin >> t;
    while (t--)
    {
        //*approach 2
        int n,k;
        cin >> n >> k;
        int low = k;
        int high = k+n-1;
        int mid = 0;
        while(low<=high){
            mid = low+(high-low)/2;
            debug(mid);
            debug(func2(mid,n,k));
            if(func2(mid,n,k) <= 0ll) low= mid+1;
            else if(func2(mid,n,k)>0ll) high = mid-1;
        }
        myFunc(low,high,mid);
        cout << min(abs(func(low,n,k)),abs((func(high,n,k)))) << endl;
        cerr << endl;







        // * approach 1
    //     int n, k;
    //     cin >> n >> k;
    //     int low = k;
    //     int high = k + n - 1;
    //     int mid = 0;
    //     debug(n);
    //     int ans = LONG_LONG_MAX;
    //     while (low <= high)
    //     {
    //         mid = low + (high - low) / 2;
    //         debug(mid);
    //         int mid_func = func(mid, n, k);
    //         int left_func = func(mid - 1, n, k);
    //         int right_func = func(mid + 1, n, k);
    //         if (right_func >= mid_func && left_func >= mid_func)
    //         {
    //             cout << mid_func << endl;
    //             break;
    //         }
    //         else if (right_func <= mid_func)
    //         {
    //             low = mid + 1;
    //         }
    //         else
    //         {
    //             high = mid - 1;
    //         }
    //     }
    }

    return 0;
}