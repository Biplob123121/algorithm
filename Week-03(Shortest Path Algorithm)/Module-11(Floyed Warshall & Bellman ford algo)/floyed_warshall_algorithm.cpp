#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
const int INF = 1e9 + 7;
int dist[N][N];
int n, m;

void dist_intialize()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                dist[i][j] = INF;
        }
    }
}

void print_matrix()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
                cout << "x ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    cin >> n >> m;

    dist_intialize();

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    print_matrix();

    // floyed warshal
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "\nAfter applying Floyed Warshall : \n";
    print_matrix();
    return 0;
}