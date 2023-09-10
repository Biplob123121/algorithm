#include <bits/stdc++.h>
using namespace std;

bool search(int ar[], int n, int k)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (ar[mid] == k)
        {
            if (ar[mid + 1] == k || ar[mid - 1] == k)
                return true;
        }
        // return mid;
        if (ar[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int k;
    cin >> k;

    bool flag = search(ar, n, k);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}