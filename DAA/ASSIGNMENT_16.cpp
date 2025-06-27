#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    int maxLength = 0;
    int endIndex = 0;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << "Length of Longest Common Substring: " << maxLength << endl;
    if (maxLength > 0) {
        cout << "Longest Common Substring: " << s1.substr(endIndex - maxLength, maxLength) << endl;
    } else {
        cout << "No common substring found." << endl;
    }

    return 0;
}
