#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
bool visited2[N];

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
void components(int u)
{
    visited2[u] = true;
    cout << u << " ";
    for (int v : adjList[u])
    {
        if (visited2[v])
            continue;
        components(v);
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
        dfs(i);
        root.push_back(i);
        cc++;
    }
    cout << cc << endl;

    int cnt = 1;
    for (int val : root)
    {
        cout << "Component " << cnt << " : ";
        components(val);
        cnt++;
        cout << endl;
    }

    return 0;
}