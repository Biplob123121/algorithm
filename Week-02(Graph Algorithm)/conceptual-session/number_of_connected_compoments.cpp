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
        if (visited[v] == true)
            continue;
        dfs(v);
    }
}
void connectedComp(int u)
{
    visited2[u] = true;
    cout << u << " ";
    for (int v : adjList[u])
    {
        if (visited2[v] == true)
            continue;
        connectedComp(v);
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
    vector<int> cmp;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        cmp.push_back(i);
        cc++;
    }
    cout << "Number of Connected Components : " << cc << endl;
    for (int val : cmp)
    {
        cout << "Components " << val << " : ";
        connectedComp(val);
        cout << endl;
    }

    return 0;
}