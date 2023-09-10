#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector<int> adjList[N];
bool visited[N];

void dfs(int u, int &cnt)
{
    visited[u] = true;
    cnt++;
    for (int v : adjList[u])
    {
        if (visited[v])
            continue;
        dfs(v, cnt);
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

    vector<int> componentNum;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == true && adjList[i].empty())
            continue;
        int cnt = 0;
        dfs(i, cnt);
        if (cnt > 1)
            componentNum.push_back(cnt);
    }

    sort(componentNum.begin(), componentNum.end());

    for (int val : componentNum)
        cout << val << " ";

    return 0;
}