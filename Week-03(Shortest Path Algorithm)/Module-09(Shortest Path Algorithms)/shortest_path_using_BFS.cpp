#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> adjList[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

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

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << "Parent of " << i << " : " << parent[i] << endl;
    // }
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Shortest Path : ";
    for (int node : path)
    {
        cout << node << " ";
    }

    return 0;
}