#include <bits/stdc++.h>
using namespace std;

// Directions for 4‑way movement
static const int dr[4] = {-1, +1, 0, 0};
static const int dc[4] = { 0,  0, -1, +1};

/**
 * Perform a BFS from (si, sj) on grid A[M][N], 
 * collecting at most two distinct values. 
 * Uses a shared `visited` array keyed by `run_id`.
 */
int bfs(int si, int sj,
        int M, int N,
        const vector<vector<int>>& A,
        vector<vector<int>>& visited,
        int run_id)
{
    unordered_set<int> types;
    queue<pair<int,int>> q;

    types.insert(A[si][sj]);
    visited[si][sj] = run_id;
    q.emplace(si, sj);
    int cnt = 1;

    while (!q.empty()) {
        auto [r, c] = q.front(); 
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= M || nc < 0 || nc >= N) 
                continue;
            if (visited[nr][nc] == run_id) 
                continue;

            int v = A[nr][nc];
            // can we add this type?
            if (types.count(v) || types.size() < 2) {
                types.insert(v);
                visited[nr][nc] = run_id;
                q.emplace(nr, nc);
                ++cnt;
            }
        }
    }

    return cnt;
}

int numberOfFlowers(int M, int N, vector<vector<int>>& A) {
    int best = 0;
    vector<vector<int>> visited(M, vector<int>(N, 0));
    int run_id = 0;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            ++run_id;  // new BFS “stamp”
            best = max(best, bfs(i, j, M, N, A, visited, run_id));
            if (best == M * N) 
                return best;
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
