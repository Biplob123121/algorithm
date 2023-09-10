#include <bits/stdc++.h>
using namespace std;

void merge(int ar1[], int ar2[], int n, int m, int result[])
{
    int x = 0, y = 0, k = 0;

    while (x < n && y < m)
    {
        if (ar1[x] > ar2[y])
        {
            result[k] = ar1[x];
            k++;
            x++;
        }
        else
        {
            result[k] = ar2[y];
            k++;
            y++;
        }
    }
    while (x < n)
    {
        result[k] = ar1[x];
        k++;
        x++;
    }
    while (y < m)
    {
        result[k] = ar2[y];
        k++;
        y++;
    }
}

int main()
{
    int n;
    cin >> n;
    int ar1[n];

    for (int i = 0; i < n; i++)
        cin >> ar1[i];

    int m;
    cin >> m;
    int ar2[m];

    for (int i = 0; i < m; i++)
        cin >> ar2[i];

    int result[n + m];

    merge(ar1, ar2, n, m, result);

    for (int val : result)
        cout << val << " ";
    cout << endl;
    return 0;
}