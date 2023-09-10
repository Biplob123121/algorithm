#include <bits/stdc++.h>
using namespace std;

typedef pair<int, long long> pii;

const int N = 1e5 + 7;
const long long INF = 1e18 + 7;
vector<pii> adjList[N];
vector<long long> dist(N, INF);
vector<bool> visited(N, false);

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
            long long w = vpair.second;

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
    while (m--)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }

    int q;
    cin >> q;
    while (q--)
    {
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            dist[i] = INF;
        }
        int s, d;
        cin >> s >> d;
        dijkstra(s);

        if (dist[d] == INF)
            cout << -1 << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}