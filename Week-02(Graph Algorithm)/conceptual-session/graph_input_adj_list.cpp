#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
int visited[N];
int level[N];

void dfs(int u)
{
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adjList[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
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
    bfs(0);
    for (int i = 0; i < n; i++)
    {
        if(level[i]==2) cout<<i<<" ";
    }
    return 0;
}