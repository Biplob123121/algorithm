#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
vector<pii> adjList[N];
vector<bool> visited(N);
vector<int> dist(N, INF);

void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({dist[src], src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pii vpair : adjList[u])
        {
            int v = vpair.first;
            int w = vpair.second;

            if (visited[v])
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
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