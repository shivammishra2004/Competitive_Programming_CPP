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

bool arrEqual(vector<int> v1, vector<int> v2)
{
    bool flag = true;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool compare(int a, int b) {
    return a > b; // '>' for descending order
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    vector<int> sortedv1(v1);
    sort(sortedv1.begin(), sortedv1.end(),compare);
    bool one = arrEqual(sortedv1, v1);
    bool two = arrEqual(v1, v2);
    debug(v1);
    debug(v2);
    debug(sortedv1);
    debug(one);
    debug(two);
    if (!two)
    {
        cout << "rated";
        return 0;
    }
    else if (one && two)
    {
        cout << "maybe";
        return 0;
    }
    else if (!one && two)
    {
        cout << "unrated";
        return 0;
    }

    return 0;
}