#include <bits/stdc++.h>
using namespace std;
int main()
{
    int e;
    cin >> e;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        pq.push({u, v});
    }

    while (!pq.empty())
    {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}