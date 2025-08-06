#include <bits/stdc++.h>
using namespace std;

void findMostRecurrentSequences(int N, vector<string>& keywords) {
    map<string, int> freq;

    for (int k = 0; k < N; ++k) {
        string s = keywords[k];
        if (s.length() < 3) continue;

        for (int i = 0; i <= s.length() - 3; ++i) {
            for (int len = 3; i + len <= s.length(); ++len) {
                freq[s.substr(i, len)]++;
            }
        }
    }

    vector<string> res;

    for (auto& p : freq) {
        if (p.second > 1) {
            string t = p.first;
            if (next_permutation(t.begin(), t.end())) {
                res.push_back(t);
            } else {
                res.push_back(p.first);
            }
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string line;
    getline(cin, line);

    vector<string> keywords;
    stringstream ss(line);
    string keyword;
    while (ss >> keyword) {
        keywords.push_back(keyword);
    }

    findMostRecurrentSequences(N, keywords);

    return 0;
}
