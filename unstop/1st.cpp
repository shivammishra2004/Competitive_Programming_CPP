#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count the number of differing bits (bitwise difference)
int bitwiseDifference(int a, int b) {
    int xorVal = a ^ b;
    int count = 0;
    while (xorVal) {
        count += xorVal & 1;
        xorVal >>= 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int maxDiff = 0;

    // Iterate over all subarrays
    for (int i = 0; i < n; ++i) {
        int minVal = arr[i];
        int maxVal = arr[i];
        for (int j = i; j < n; ++j) {
            minVal = min(minVal, arr[j]);
            maxVal = max(maxVal, arr[j]);

            if (i != j) { // Subarray length > 1
                int diff = bitwiseDifference(minVal, maxVal);
                maxDiff = max(maxDiff, diff);
            }
        }
    }

    cout << maxDiff << endl;
    return 0;
}
