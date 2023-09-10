#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int N, E, Q;
    cin >> N >> E;
    
    // Create an adjacency list to store the graph
    vector<vector<pair<int, int>>> graph(N + 1);
    
    for (int i = 0; i < E; ++i) {
        int A, B, W;
        cin >> A >> B >> W;
        graph[A].emplace_back(B, W);
    }
    
    cin >> Q;
    
    for (int q = 0; q < Q; ++q) {
        int X, Y;
        cin >> X >> Y;
        
        // Initialize distances to infinity
        vector<long long> dist(N + 1, INF);
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        dist[X] = 0;
        pq.emplace(0, X);
        
        while (!pq.empty()) {
            int u = pq.top().second;
            long long d = pq.top().first;
            pq.pop();
            
            if (d > dist[u]) {
                continue;
            }
            
            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;
                
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        
        // Print the result
        if (dist[Y] == INF) {
            cout << "-1" << endl;
        } else {
            cout << dist[Y] << endl;
        }
    }
    
    return 0;
}
