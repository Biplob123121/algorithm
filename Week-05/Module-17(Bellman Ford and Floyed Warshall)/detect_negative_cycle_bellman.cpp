#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Edge> v;

    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

    int dist[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            if (dist[a] + w < dist[b])
            {
                dist[b] = dist[a] + w;
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;

            if (dist[a] + w < dist[b])
            {
                flag = true;
                break;
                dist[b] = dist[a] + w;
            }
        }
    }

    if (flag)
        cout << "Cycle Exists" << endl;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Distance of " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}