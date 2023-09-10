#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
bool visited[N][N];
int dist[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int ci, int cj)
{
    if (ci >= 0 && ci < n && cj >= 0 && cj < m)
        return true;
    else
        return false;
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    dist[si][sj] = 0;

    while (!q.empty())
    {
        pii parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;

        for (int i = 0; i < 4; i++)
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
    cin >> n >> m;
    char a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}