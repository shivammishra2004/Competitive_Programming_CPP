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
// void _print(int t) { cerr << t; }
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

bool sortbysec(const pair<int,int> &a,
            const pair<int,int> &b)
{
    return (a.second < b.second);
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
        int n,p;
        cin >> n >> p;
        int ans = n*p;
        int count = n;
        vector<int> v1;
        vector<int> v2;
        while(n--){
            int a;
            cin >> a;
            v1.push_back(a);
        }
        n = count;
        while(n--){
            int a;
            cin >> a;
            v2.push_back(a);
        }
        vector<pair<int,int>> vecPair;
        for(int i = 0;i<v1.size();i++){
            vecPair.emplace_back(v1[i],v2[i]);
        }
        sort(vecPair.begin(), vecPair.end(), sortbysec);
    //     for (const auto& p : vecPair) {
    //     std::cout << "(" << p.first << ", " << p.second << ")\n";
    // }
        count--;
        int cost = p;
        for(int i = 0;i<vecPair.size();i++){
            if(vecPair[i].second<p){
                // cout << count <<  ' ';
                if(count-vecPair[i].first>0){
                    count -= vecPair[i].first;
                    cost +=  vecPair[i].first*vecPair[i].second;
                }
                else{
                    cost += count*vecPair[i].second;
                    count = 0;
                } 
                // cout << 'f' << cost << " ";
            }
        }
        if(count) cost += count*p;
        cout << min(cost, ans) << endl;
    }
    return 0;
}