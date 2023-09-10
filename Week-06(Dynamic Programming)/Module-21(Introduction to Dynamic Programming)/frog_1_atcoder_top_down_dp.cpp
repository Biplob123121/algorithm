#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int dp[N];

int solve(int ar[], int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];
    else if (n == 2)
    {
        return dp[n] = abs(ar[2] - ar[1]);
    }
    else
    {
        int choice1 = solve(ar, n - 1) + abs(ar[n] - ar[n - 1]);
        int choice2 = solve(ar, n - 2) + abs(ar[n] - ar[n - 2]);
        return dp[n] = min(choice1, choice2);
    }
}

int main()
{
    int n;
    cin >> n;
    int ar[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = -1;
        cin >> ar[i];
    }
    cout << solve(ar, n) << endl;
    return 0;
}