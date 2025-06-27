#include<bits/stdc++.h>

using namespace std;



#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(n) n.rbegin(), n.rend()
#define coutyes cout << "YES" << nl;
#define coutno cout << "NO" << nl;

// Range
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

// Types
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vii;
typedef pair<int,int> pii;
typedef set<int> si;
typedef map<int,int> mii;
typedef map<ll,ll> mll;


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

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(mll v) { cerr << "{ "; for (auto &p : v) {cerr << "(" << p.first << "," << p.second << ") ";}cerr << "}";}

ll binExpIter(ll a, ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b/=2;
    }
    return ans;
}

bool compare( const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return a.ss>b.ss;
}

void krisp()
{
    ll n,k;
    cin >> n >> k;
    vll a(n,0);
    mll mpp;
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
        mpp[a[i]]++;
        
    }
    vector<pair<ll,ll> > v(mpp.begin(), mpp.end());
    sort(all(v),compare);
    int nn=v.size();


    mll mpp2;
    for (int i=0; i<nn; i++)
    {
        if(k>0)
        {
            ll diff=min(v[i].ss-1LL, k);
            v[i].ss-=diff;
            k-=diff;
        }
        mpp2[v[i].ff]=v[i].ss;
        
    }
    debug(mpp2)

    ll ans=0;
    for (int i=0; i<n-1; i++)
    {
        ll cnt=n-1-i;
        ll sec=max(mpp2[a[i]]-1,0LL);
        if(mpp2[a[i]]>0) mpp2[a[i]]--;
        cnt-=sec;
        ans+=cnt;

        debug(mpp2)

    }
    cout << ans << nl;

}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        krisp();
    }
    return 0;
}