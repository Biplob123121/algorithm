#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

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

    int query;
    cin >> query;
    while (query--)
    {
        for (int i = 0; i < N; i++)
        {
            level[i] = 0;
            visited[i] = false;
        }
        int s, d;
        cin >> s >> d;
        bfs(s);
        if (level[d] >= 0)
            cout << level[d] << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}