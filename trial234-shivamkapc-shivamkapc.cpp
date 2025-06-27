#include <iostream>
#include <vector>
 
using namespace std;

void work(){
    int n,k,d;
    cin >> n >> d >> k;
 
    vector<int> ss(n+1),es(n+1);
 
    for (int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        ss[a]++;
        es[b]++;
    }
 
    for (int i=0;i<n;i++) ss[i+1] += ss[i];
    for (int i=0;i<n;i++) es[i+1] += es[i];
 
    int most = 0;
    int robert = 0;
    int mrs = 0;
    int least = 1e9;
    vector<int> pfs;
    for (int i=d;i<=n;i++){
        int cur = ss[i] - es[i-d];
        pfs.push_back(cur);
        if (cur > most) most = cur, robert = i-d+1;
        if (cur < least) least = cur, mrs = i-d+1;
    }
    for(auto i:pfs){
        cout << i << " ";
    }
    cout << endl;
 
    cout << robert << ' ' << mrs << "\n";
}
 
int main(){
    int t;
    cin >> t;
    while (t--) work();
 
    return 0;
}