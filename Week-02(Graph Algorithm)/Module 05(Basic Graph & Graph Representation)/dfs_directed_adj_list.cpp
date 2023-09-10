#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> adjList[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout << "Visited node : " << u << endl;
    for (int v : adjList[u])
    {
        if (visited[v] == true)
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
    }

    dfs(1);

    return 0;
}