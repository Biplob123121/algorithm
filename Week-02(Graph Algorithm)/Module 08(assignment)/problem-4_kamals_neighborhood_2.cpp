#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
int cnt=0;

void dfs(int u)
{
    visited[u] = true;

    for (int v : adjList[u])
    {
        if (visited[v] == true)
            continue;
        cnt++;
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
    int h;
    cin >> h;
    dfs(h);
    cout<<cnt<<endl;
    return 0;
}