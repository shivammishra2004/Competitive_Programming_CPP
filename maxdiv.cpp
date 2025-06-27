#include <bits/stdc++.h>
using namespace std;

#define print(arr) for(auto i: arr) { cout << i << " "; } cout << "\n";
#define int long long
#define endl '\n'

int mod = 1e9 + 7;

void zoro(){
	int n,k;
	cin>>n>>k;

	set<int> s;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		s.insert(x);
	}

	int b = s.size();

	int a = min(b+k,n);

	int extras = n - a;
	int f = a- extras;
	int sum = 0;
	n--;
	while(f--){
		sum+=n;
		n--;
	}

	cout<<sum<<endl;
}

signed main() {
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        zoro();
    }
    return 0;
}
