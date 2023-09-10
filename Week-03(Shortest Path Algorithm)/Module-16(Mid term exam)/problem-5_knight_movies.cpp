#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
bool visited[N][N];
int dist[N][N];
vector<pii> path = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
int n, m;

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void bfs(int ki, int kj, int qi, int qj)
{
    queue<pii> q;
    q.push({ki, kj});
    visited[ki][kj] = true;
    dist[ki][kj] = 0;

    while (!q.empty())
    {
        pii parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;

        if (pi == qi && pj == qj)
            return;

        for (int i = 0; i < 8; i++)
        {
            pii p = path[i];
            int ci = pi + p.first;
            int cj = pj + p.second;

            if (isValid(ci, cj) && !visited[ci][cj])
            {
                visited[ci][cj] = true;
                q.push({ci, cj});
                dist[ci][cj] = dist[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ki, kj, qi, qj;
        cin >> n >> m;
        cin >> ki >> kj;
        cin >> qi >> qj;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[i][j] = -1;
                visited[i][j] = false;
            }
        }

        bfs(ki, kj, qi, qj);
        cout << dist[qi][qj] << endl;
    }

    return 0;
}