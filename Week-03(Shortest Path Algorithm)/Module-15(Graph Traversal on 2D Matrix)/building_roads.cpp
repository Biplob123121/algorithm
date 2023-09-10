#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> adjList[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (visited[v])
            continue;
        dfs(v);
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
    vector<int> root;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        cc++;
        dfs(i);
        root.push_back(i);
    }
    cout << cc - 1 << endl;

    for (int i = 0; i < cc - 1; i++)
    {
        cout << root[i] << " " << root[i + 1] << endl;
    }
    return 0;
}