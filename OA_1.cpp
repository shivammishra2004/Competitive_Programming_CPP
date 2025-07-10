#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    // Input: n (number of facilities), k (length to remove)
    cin >> n >> k;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << n << endl;

    // If k >= n, all facilities removed → no connections
    if(k >= n){
        cout << 0 << "\n";
        return 0;
    }

    // Build diff[i] = |nums[i] - nums[i-1]| for i = 1..n-1
    vector<ll> diff(n, 0);
    for(int i = 1; i < n; i++){
        diff[i] = llabs(nums[i] - nums[i-1]);
    }

    // initial total cost
    ll initial = 0;
    for(int i = 1; i < n; i++){
        initial += diff[i];
    }

    // prefix sums over diff: pfs[i] = sum diff[1..i]
    vector<ll> pfs(n, 0);
    for(int i = 1; i < n; i++){
        pfs[i] = pfs[i-1] + diff[i];
    }

    ll ans = LLONG_MAX;
    // slide window [l..r] of size k
    for(int l = 0; l + k - 1 < n; l++){
        int r = l + k - 1;

        // sum of diffs we remove entirely
        ll removed_internal = pfs[r] - (l > 0 ? pfs[l-1] : 0);

        // boundary edges to remove
        ll removed_left  = (l > 0         ? diff[l]   : 0);
        ll removed_right = (r + 1 < n    ? diff[r+1] : 0);

        // new bridge if both neighbors exist
        ll added_bridge = 0;
        if(l > 0 && r + 1 < n){
            added_bridge = llabs(nums[r+1] - nums[l-1]);
        }

        ll new_cost = initial
                      - removed_internal
                      - removed_left
                      - removed_right
                      + added_bridge;

        ans = min(ans, new_cost);
    }

    cout << ans << "\n";
    return 0;
}
