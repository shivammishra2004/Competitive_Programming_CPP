#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple> // For std::tuple and std::get

using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x), rootY = find(y);
        if (rootX == rootY) return false;
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            ++rank[rootX];
        }
        return true;
    }
};

long long Mincurr(int n, vector<int>& vis, vector<int>& curr) {
    vector<tuple<long long, int, int>> connections;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            long long distance = (long long)min(curr[i], curr[j]) * abs(vis[i] - vis[j]);
            connections.emplace_back(distance, i, j);
        }
    }

    sort(connections.begin(), connections.end());

    UnionFind uf(n);
    long long result = 0;
    int connected = 0;

    for (const auto& connection : connections) {
        long long distance = get<0>(connection);
        int point1 = get<1>(connection);
        int point2 = get<2>(connection);

        if (uf.unite(point1, point2)) {
            result += distance;
            ++connected;
            if (connected == n - 1) break;
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> vis(n), curr(n);
        for (int i = 0; i < n; ++i) {
            cin >> vis[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> curr[i];
        }

        cout << Mincurr(n, vis, curr) << endl;
    }

    return 0;
}
