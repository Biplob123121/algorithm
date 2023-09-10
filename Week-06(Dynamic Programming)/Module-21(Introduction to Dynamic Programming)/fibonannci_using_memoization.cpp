#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int save[N];

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (save[n] != -1)
    {
        return save[n];
    }
    save[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return save[n];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i <= n; i++)
    {
        save[i] = -1;
    }
    cout << fibonacci(n) << endl;
    return 0;
}