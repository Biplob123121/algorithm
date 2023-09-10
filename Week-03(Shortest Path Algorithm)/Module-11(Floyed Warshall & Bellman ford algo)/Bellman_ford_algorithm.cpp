#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pii> adjList[N];
vector<pair<pii, int>> list_of_edges;
int dist[N];
int n, m;

// void bellman_ford(int src)
// {
//     for (int i = 1; i <= n; i++)
//         dist[i] = INF;

//     dist[src] = 0;

//     for (int i = 1; i < n; i++)
//     {
//         for (int u = 1; u <= n; u++)
//         {
//             for (pii vpair : adjList[u])
//             {
//                 int v = vpair.first;
//                 int w = vpair.second;
//                 if (dist[u] != INF && dist[v] > dist[u] + w)
//                 {
//                     dist[v] = dist[u] + w;
//                 }
//             }
//         }
//     }
// }

// using list_of edges
void bellman_ford(int src)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (auto edge : list_of_edges)
    {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        if (dist[u] != INF && dist[v] > dist[u] + w)
        {
            dist[v] = dist[u] + w;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        list_of_edges.push_back({{u, v}, w});
    }

    bellman_ford(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of " << i << " : " << dist[i] << endl;
    }
    return 0;
}