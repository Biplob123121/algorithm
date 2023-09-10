#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 7;
vector<pii> adjList[N];

void dijkstra(int src)
{
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w});
    }
    return 0;
}