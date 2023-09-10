#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<bool> visited(N, false);
vector<int> adjList[N];
vector<int> level(N, 0);
vector<int> parent(N, -1);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    level[src] = 0;
    parent[src] = 0;
    visited[src] = true;

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

    bfs(1);

    cout << level[n] << endl;

    int curr=n;
    vector<int> path;
    while (curr!=-1)
    {
        path.push_back(curr);
        curr=parent[curr];
    }
    reverse(path.begin(), path.end());

    for(int node:path){
        cout<<node<<" ";
    }
    return 0;
}