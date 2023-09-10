#include <bits/stdc++.h>
using namespace std;

int searchIndex(int ar[], int n, int k)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (ar[mid] == k)
            return mid;
        if (ar[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int ar[n];

    for(int i=0; i<n;i++) cin>>ar[i];

    int k;
    cin>>k;

    int flag = searchIndex(ar, n, k);
    if(flag>-1) cout<<flag<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}