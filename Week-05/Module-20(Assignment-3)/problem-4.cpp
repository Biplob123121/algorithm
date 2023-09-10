#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

const long long INF = 1e18 + 7;
const int N = 1e3 + 7;
vector<Edge> v;
int n, m;

bool bellman_ford(int src, vector<long long> &dist)
{
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            long long w = ed.w;

            if (dist[a] != INF && dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            long long w = ed.w;

            if (dist[a] != INF && dist[a] + w < dist[b])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int src;
    cin >> src;

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        cin >> d;

        vector<long long> dist(n + 1, INF);

        bool flag = bellman_ford(src, dist);
        if (flag == false)
        {
            cout << "Negative Cycle Detected" << endl;
            break;
        }
        else
        {
            if (dist[d] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dist[d] << endl;
            }
        }
    }

    return 0;
}