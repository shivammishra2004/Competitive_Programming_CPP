#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Z, O, L;
    cin >> Z >> O >> L;

    // dpZ[i][j]: # ways using i zeros and j ones, ending in a zero
    // dpO[i][j]: # ways using i zeros and j ones, ending in a one
    vector<vector<int>> dpZ(Z+1, vector<int>(O+1, 0));
    vector<vector<int>> dpO(Z+1, vector<int>(O+1, 0));

    // prefO[i][j]: sum_{x=0..i} dpO[x][j]
    // prefZ[i][j]: sum_{y=0..j} dpZ[i][y]
    vector<vector<int>> prefO(Z+1, vector<int>(O+1, 0));
    vector<vector<int>> prefZ(Z+1, vector<int>(O+1, 0));

    // Base case: empty sequence counted once in each (matches original logic)
    dpZ[0][0] = dpO[0][0] = 1;
    prefO[0][0] = 1;
    prefZ[0][0] = 1;

    for (int i = 0; i <= Z; ++i) {
        for (int j = 0; j <= O; ++j) {
            if (i == 0 && j == 0) continue;

            // Build dpZ[i][j] by appending zeros to sequences ending in 1
            if (i > 0) {
                long long total = prefO[i-1][j];
                if (i - L - 1 >= 0) 
                    total = (total - prefO[i-L-1][j] + MOD) % MOD;
                dpZ[i][j] = total;
            }

            // Build dpO[i][j] by appending ones to sequences ending in 0
            if (j > 0) {
                long long total = prefZ[i][j-1];
                if (j - L - 1 >= 0)
                    total = (total - prefZ[i][j-L-1] + MOD) % MOD;
                dpO[i][j] = total;
            }

            // Update prefix sums
            prefO[i][j] = dpO[i][j] + (i > 0 ? prefO[i-1][j] : 0);
            prefZ[i][j] = dpZ[i][j] + (j > 0 ? prefZ[i][j-1] : 0);
            if (prefO[i][j] >= MOD) prefO[i][j] -= MOD;
            if (prefZ[i][j] >= MOD) prefZ[i][j] -= MOD;
        }
    }

    // Answer is total ways ending in 0 plus ways ending in 1
    cout << ( (long long)dpZ[Z][O] + dpO[Z][O] ) % MOD << "\n";
    return 0;
}
