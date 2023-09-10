#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2)
{
    int sz1 = v1.size();
    int sz2 = v2.size();
    vector<int> ans;

    int i = 0, j = 0;

    while (i < sz1 && j < sz2)
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }

    while (i < sz1)
    {
        ans.push_back(v1[i]);
        i++;
    }

    while (j < sz2)
    {
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v1(n);
    vector<int> v2(m);

    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];

    vector<int> ans = merge(v1, v2);

    for (int val : ans)
        cout << val << " ";

    return 0;
}