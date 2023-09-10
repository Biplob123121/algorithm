#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;
vector<pii> adjList[N];
vector<int> dist(N, INF);
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
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int s;
    cin >> s;
    dijkstra(s);

    int t;
    cin >> t;
    while (t--)
    {
        int d, cost;
        cin >> d >> cost;
        if (dist[d] <= cost)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}