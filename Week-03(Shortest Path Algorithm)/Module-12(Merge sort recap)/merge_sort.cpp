#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int mid, int r)
{
    int leftSize = mid - l + 1;
    int rightSize = r - (mid+1)+1;

    int leftArr[leftSize];
    int rightArr[rightSize];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        leftArr[j] = nums[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        rightArr[j] = nums[i];
    }

    int lp = 0, rp = 0, k = l;

    while (lp < leftSize && rp < rightSize)
    {
        if (leftArr[lp] < rightArr[rp])
        {
            nums[k] = leftArr[lp];
            lp++;
            k++;
        }
        else
        {
            nums[k] = rightArr[rp];
            rp++;
            k++;
        }
    }

    while (lp < leftSize)
    {
        nums[k] = leftArr[lp];
        lp++;
        k++;
    }
    while (rp < rightSize)
    {
        nums[k] = rightArr[rp];
        rp++;
        k++;
    }
}

void mergeSort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    mergeSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    return 0;
}