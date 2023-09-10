#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int dp[N];

int main()
{
    int n;
    cin >> n;
    int ar[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dp[i] = INT_MAX;
        cin >> ar[i];
    }

    dp[1] = 0;
    dp[2] = abs(ar[2] - ar[1]);

    for (int i = 3; i <= n; i++)
    {
        int ch1 = dp[i - 2] + abs(ar[i] - ar[i - 2]);
        int ch2 = dp[i - 1] + abs(ar[i] - ar[i - 1]);
        dp[i] = min(ch1, ch2);
    }

    cout << dp[n] << endl;
    return 0;
}