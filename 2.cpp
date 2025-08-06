#include <bits/stdc++.h>
using namespace std;

// Returns the size of the largest connected area containing at most two distinct flower types.
int numberOfFlowers(int M, int N, vector<vector<int>>& A) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int best = 0;

    // For each starting cell, do a BFS allowing up to two distinct values.
    for (int si = 0; si < M; ++si) {
        for (int sj = 0; sj < N; ++sj) {
            vector<vector<bool>> seen(M, vector<bool>(N, false));
            queue<pair<int,int>> q;
            unordered_set<int> types;
            
            // start BFS from (si,sj)
            types.insert(A[si][sj]);
            seen[si][sj] = true;
            q.emplace(si, sj);
            int cnt = 1;

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
                    if (seen[nr][nc]) continue;
                    int v = A[nr][nc];
                    // if it's one of the types we already have, or we have room for one more type
                    if (types.count(v) || types.size() < 2) {
                        types.insert(v);
                        seen[nr][nc] = true;
                        q.emplace(nr, nc);
                        ++cnt;
                    }
                }
            }

            best = max(best, cnt);
            // early exit: you can't beat picking every cell
            if (best == M * N) return best;
        }
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    vector<vector<int>> A(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> A[i][j];

    cout << numberOfFlowers(M, N, A) << "\n";
    return 0;
}
