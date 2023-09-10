#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX_N = 101; // Maximum number of nodes
const long long INF = LLONG_MAX / 2; // A very large value to represent infinity

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<long long>> dist(MAX_N, vector<long long>(MAX_N, INF));

    // Initialize distances for direct edges
    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        dist[A][B] = min(dist[A][B], (long long)W);
    }

    // Initialize diagonal distances to 0
    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int Q;
    cin >> Q;

    // Process the queries
    for (int q = 0; q < Q; ++q) {
        int X, Y;
        cin >> X >> Y;

        if (dist[X][Y] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[X][Y] << endl;
        }
    }

    return 0;
}
