#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

void printPath(int v, const vector<int>& parent) {
    if (v == -1) return;
    printPath(parent[v], parent);
    cout << v << " ";
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Enter edges in format (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }

    // Check for negative weight cycles
    bool negativeCycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.u] != INT_MAX && dist[edge.u] + edge.weight < dist[edge.v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Graph contains a negative weight cycle.\n";
    } else {
        cout << "Shortest distances and paths from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Vertex " << i << ": Unreachable\n";
            } else {
                cout << "Vertex " << i << ": Distance = " << dist[i] << ", Path = ";
                printPath(i, parent);
                cout << "\n";
            }
        }
    }

    return 0;
}
