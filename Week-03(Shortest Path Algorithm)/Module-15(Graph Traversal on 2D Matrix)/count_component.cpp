#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> adjList[N];
bool visited[N];
vector<int> cmp;

void dfs(int u)
{
    visited[u] = true;
    cmp.push_back(u);

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

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        cc++;
        dfs(i);
        for (int val : cmp)
        {
            cout << val << " ";
        }
        cout << endl;
        cmp.clear();
    }

    cout << cc << endl;
    return 0;
}