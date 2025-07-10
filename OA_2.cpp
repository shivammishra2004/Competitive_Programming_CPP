#include <bits/stdc++.h>
using namespace std;

long getMaximumPrizes(const string &s) {
    int n = s.size();
    vector<long> pfsA(n+1, 0), pfsAM(n+1, 0), sfsZ(n+1, 0), sfsMZ(n+1, 0);
    for (int i = 0; i < n; i++) {
        pfsA[i+1]  = pfsA[i] + (s[i]=='A');
        pfsAM[i+1] = pfsAM[i] + (s[i]=='M' ? pfsA[i] : 0);
    }
    for (int i = n-1; i >= 0; i--) {
        sfsZ[i]   = sfsZ[i+1] + (s[i]=='Z');
        sfsMZ[i]  = sfsMZ[i+1] + (s[i]=='M' ? sfsZ[i+1] : 0);
    }
    long ans = 0, am = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='M') am += pfsA[i];
        else if (s[i]=='Z') ans += am;
    }
    for (int i = 0; i <= n; i++) {
        long withA = ans + sfsMZ[i];
        long withM = ans + pfsA[i] * sfsZ[i];
        long withZ = ans + pfsAM[i];
        ans = max(ans, max(withA, max(withM, withZ)));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << getMaximumPrizes(s);
    return 0;
}
