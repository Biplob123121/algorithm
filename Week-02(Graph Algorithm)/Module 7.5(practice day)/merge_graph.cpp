#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector<int> adjList[N];
bool visited[N];
bool visited2[N];
vector<int> v1;
vector<int> v2;

vector<int> merge(vector<int> v1, vector<int> v2)
{
    int size1 = v1.size();
    int size2 = v2.size();
    int f = 0, l = 0, k = 0;

    vector<int> ans;
    while (f < size1 && l < size2)
    {
        if (v1[f] < v2[l])
        {
            ans.push_back(v1[f]);
            f++;
        }
        else
        {
            ans.push_back(v2[l]);
            l++;
        }
    }
    while (f < size1)
    {
        ans.push_back(v1[f]);
        f++;
    }
    while (l < size2)
    {
        ans.push_back(v2[l]);
        l++;
    }
    return ans;
}
void dfs(int u)
{
    visited[u] = true;
    for (int v : adjList[u])
    {
        if (visited[v])
            continue;
        dfs(v);
    }
}
void components(int u, int cnt)
{
    visited2[u] = true;
    cout << u << " ";
    if (cnt == 1)
        v1.push_back(u);
    else
        v2.push_back(u);
    for (int v : adjList[u])
    {
        if (visited2[v])
            continue;
        components(v, cnt);
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
        adjList[v].push_back(u);
    }

    int cc = 0;
    vector<int> root;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        root.push_back(i);
        cc++;
    }
    cout << cc << endl;

    int cnt = 1;
    for (int val : root)
    {
        cout << "Component " << cnt << " : ";
        components(val, cnt);
        cnt++;
        cout << endl;
    }

    cout << "Merge graph : ";
    vector<int> ans = merge(v1, v2);
    for (int val : ans)
    {
        cout << val << " ";
    }
    return 0;
}