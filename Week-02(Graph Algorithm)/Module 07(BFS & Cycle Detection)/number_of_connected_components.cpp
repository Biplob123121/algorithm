#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];

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

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : adjList[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
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
    int cc = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cc++;
    }
    cout << "Number of Connected Components : " << cc << endl;

    return 0;
}