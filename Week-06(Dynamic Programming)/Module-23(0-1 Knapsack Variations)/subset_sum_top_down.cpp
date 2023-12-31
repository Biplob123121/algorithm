#include <bits/stdc++.h>
using namespace std;

bool subset_sum(int n, int s, int ar[])
{
    if (n == 0)
    {
        if (s == 0)
            return true;
        else
            return false;
    }
    if (ar[n - 1] <= s)
    {
        bool op1 = subset_sum(n - 1, s - ar[n - 1], ar);
        bool op2 = subset_sum(n - 1, s, ar);
        return op1 || op2;
    }
    else
    {
        return subset_sum(n - 1, s, ar);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int s;
    cin >> s;

    if (subset_sum(n, s, ar))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}