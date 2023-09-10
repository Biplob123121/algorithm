#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pair<int, int>> adjList[N];
vector<int> dist(N, INF);

void dijkstra(int src)
{
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (pair<int, int> child : adjList[u])
        {
            int v = child.first;
            int w = child.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++)
    {
        cout << "Distance of Node " << i << " : " << dist[i] << endl;
    }
    return 0;
}