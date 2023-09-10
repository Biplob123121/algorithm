#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int N, E, Q;
    cin >> N >> E;
    
    // Initialize the distance matrix with infinity
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, INF));
    
    // Set diagonal elements to 0
    for (int i = 1; i <= N; ++i) {
        dist[i][i] = 0;
    }
    
    // Read edge information
    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        dist[A][B] = W;
    }
    
    // Apply Floyd-Warshall algorithm
    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    cin >> Q;
    
    for (int q = 0; q < Q; ++q) {
        int X, Y;
        cin >> X >> Y;
        
        if (dist[X][Y] == INF) {
            cout << "-1" << endl;
        } else {
            cout << dist[X][Y] << endl;
        }
    }
    
    return 0;
}
