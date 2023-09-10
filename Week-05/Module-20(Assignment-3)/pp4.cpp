#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int from, to, weight;
};

const int INF = 1e9;

bool bellmanFord(int n, vector<Edge>& edges, int source, vector<int>& distances) {
    distances[source] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const Edge& edge : edges) {
            if (distances[edge.from] != INF && distances[edge.from] + edge.weight < distances[edge.to]) {
                distances[edge.to] = distances[edge.from] + edge.weight;
            }
        }
    }

    for (const Edge& edge : edges) {
        if (distances[edge.from] != INF && distances[edge.from] + edge.weight < distances[edge.to]) {
            return false; // Negative weight cycle detected
        }
    }

    return true;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<Edge> edges(e);
    for (int i = 0; i < e; ++i) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    int source;
    cin >> source;

    int t;
    cin >> t;

    while (t--) {
        int destination;
        cin >> destination;

        vector<int> distances(n + 1, INF);

        if (bellmanFord(n, edges, source, distances)) {
            if (distances[destination] == INF) {
                cout << "Not Possible" << endl;
            } else {
                cout << distances[destination] << endl;
            }
        } else {
            cout << "Negative Cycle Detected" << endl;
        }
    }

    return 0;
}
