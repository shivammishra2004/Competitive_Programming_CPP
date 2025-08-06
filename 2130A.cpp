#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (nums[0] == 0) {
        cout << -1;
        return 0;
    }

    int ans = 0;
    int currEnd = 0;
    int furthest = 0;
    for (int i = 0; i < n - 1; i++) {
        furthest = max(furthest, i + nums[i]);
        if (i == currEnd) {
            ans++;
            currEnd = furthest;
            if (currEnd <= i) {
                cout << -1;
                return 0;
            }
        }
    }

    if (currEnd < n - 1) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}
