#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int B) {
        int n = nums.size();
        // best[i] = minimum cost seen so far for the item that will end up at position i
        vector<long long> best(n);
        long long sum_best = 0;
        for (int i = 0; i < n; ++i) {
            best[i] = nums[i];
            sum_best += best[i];
        }
        for(auto &i: best) cout << i << " ";
        
        long long ans = sum_best;          // cost with 0 rotations
        // try performing r rotations in total (r = 1 .. n-1)
        for (int r = 1; r < n; ++r) {
            // update best[]: after one more left-rotation,
            // the element nums[(i+r) % n] can reach position i
            for (int i = 0; i < n; ++i) {
                int src = (i + r) % n;
                if (nums[src] < best[i]) {
                    sum_best -= best[i] - nums[src];
                    best[i] = nums[src];
                }
            }
            // total cost = cost of r rotations + sum of best prices
            long long total_cost = 1LL * r * B + sum_best;
            ans = min(ans, total_cost);
        }
        cout << endl;
                for(auto &i: best) cout << i << " ";
        
        return (int)ans;
    }
};

int main() {
    Solution sol;
    vector<int> A = {7, 4, 2, 1};
    int B = 3;
    cout << sol.solve(A, B) << "\n";  // outputs 11
    return 0;
}
