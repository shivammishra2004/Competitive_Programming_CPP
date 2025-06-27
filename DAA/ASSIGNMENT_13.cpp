#include <bits/stdc++.h>
using namespace std;

const int V = 9;

void dijkstra(vector<pair<int, int>> adj[], int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t\tINF\n";
        } else {
            cout << i << "\t\t" << dist[i] << endl;
        }
    }
}

int main() {
    vector<pair<int, int>> adj[V];

    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[3].push_back({5, 14});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 14});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[7].push_back({0, 8});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    int source = 0;
    dijkstra(adj, source);

    return 0;
}
