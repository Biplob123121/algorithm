#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 7;
bool visited[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;
char a[N][N];
int cnt;
bool flag = false;

bool isValid(int si, int sj)
{
    if (si >= 0 && si < n && sj >= 0 && sj < m && a[si][sj] == '.')
        return true;
    else
        return false;
}

void dfs(int si, int sj)
{
    visited[si][sj] = true;
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        pii p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{

    cin >> n >> m;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '.')
                flag = true;
        }
    }

    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && a[i][j] == '.')
                {
                    cnt = 0;
                    dfs(i, j);
                    mn = min(cnt, mn);
                }
            }
        }
        cout << mn << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}