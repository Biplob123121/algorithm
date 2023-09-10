#include <bits/stdc++.h>
using namespace std;

void merge(int ar[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int L[leftSize];
    int R[rightSize];

    for (int i = l, j = 0; i <= m; i++, j++)
    {
        L[j] = ar[i];
    }
    for (int i = m + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = ar[i];
    }

    // for (int i = 0; i < leftSize; i++)
    //     cout << L[i] << " ";
    // cout << endl;
    // for (int i = 0; i < rightSize; i++)
    //     cout << R[i] << " ";
    int lp = 0, rp = 0, k = l;
    while (lp < leftSize && rp < rightSize)
    {
        if (L[lp] < R[rp])
        {
            ar[k] = L[lp];
            lp++;
            k++;
        }
        else
        {
            ar[k] = R[rp];
            rp++;
            k++;
        }
    }

    while (lp < leftSize)
    {
        ar[k] = L[lp];
        lp++;
        k++;
    }
    while (rp < rightSize)
    {
        ar[k] = R[rp];
        rp++;
        k++;
    }
}

void mergeSort(int ar[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(ar, l, mid);
        mergeSort(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];

    mergeSort(ar, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    return 0;
}