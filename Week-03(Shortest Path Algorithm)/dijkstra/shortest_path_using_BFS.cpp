#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
vector<bool> visited(N);
int level[N];
int parent[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    parent[src] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adjList[u])
        {
            if (visited[v])
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int s, d;
    cin >> s >> d;

    bfs(s);

    cout << "Distance : " << level[d] << endl;

    int curr = d;
    vector<int> path;

    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest path : ";
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}