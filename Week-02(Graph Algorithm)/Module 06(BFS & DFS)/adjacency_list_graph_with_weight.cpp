#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> adjList[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back({v, w}); // only for undirected
        // adjList[v].push_back(u)  // for directed both
    }

    for (int i = 1; i <= n; i++)
    {
        cout<<"List "<<i<<": ";
        for (pair<int, int> j : adjList[i])
        {
            cout << "(" << j.first << ", " << j.second << ")"
                 << " ";
        }
        cout << endl;
    }
    return 0;
}