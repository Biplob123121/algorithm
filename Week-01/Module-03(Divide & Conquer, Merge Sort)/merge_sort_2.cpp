#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int l, int r, int mid)
{
    int left_size = mid - l + 1;
    int L[left_size + 1];

    int right_size = r - (mid + 1) + 1;
    int R[right_size];

    for (int i = l, j = 0; i <= mid; i++, j++)
        L[j] = v[i];

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = v[i];

    L[left_size] = INT_MAX;
    R[right_size] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            v[i] = L[lp];
            lp++;
        }
        else
        {
            v[i] = R[rp];
            rp++;
        }
    }
}

void mergeSort(vector<int> &v, int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(v, l, mid);
    mergeSort(v, mid + 1, r);
    merge(v, l, r, mid);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    mergeSort(v, 0, n - 1);

    for (int val : v)
        cout << val << " ";
    cout << endl;
    return 0;
}