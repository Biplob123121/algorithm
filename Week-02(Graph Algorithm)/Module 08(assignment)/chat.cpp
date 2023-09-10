#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

int main() {
    int N, E;
    cin >> N >> E;

    vector<vector<int>> graph(N + 1); // +1 because nodes are 1-based
    for (int i = 0; i < E; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A); // undirected graph
    }

    vector<int> componentSizes;
    vector<bool> visited(N + 1, false);
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, graph, visited, count);
            if (count > 1) { // Ignore single node components
                componentSizes.push_back(count);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());

    for (int size : componentSizes) {
        cout << size << " ";
    }

    return 0;
}
