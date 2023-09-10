#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18 + 7;

class Edge
{
public:
    int u, v;
    long long w;
    Edge(int u, int v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;

    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int s, d;
        cin >> s >> d;

        vector<long long> dist(n + 1, INF);
        dist[s] = 0;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                Edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                long long int w = ed.w;

                if (dist[a] != INF && dist[a] + w < dist[b])
                {
                    dist[b] = dist[a] + w;
                }
            }
        }
        if (dist[d] == INF)
            cout << -1 << endl;
        else
            cout << dist[d] << endl;
    }

    return 0;
}