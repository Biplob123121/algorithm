#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];

bool isCycle(int u, int p = -1)
{
    bool cycleExists = false;
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (v == p)
            continue;
        if (visited[v] == true)
            return true;
        cycleExists = cycleExists | isCycle(v, u);
    }
    return cycleExists;
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

    if (isCycle(1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
        
    return 0;
}