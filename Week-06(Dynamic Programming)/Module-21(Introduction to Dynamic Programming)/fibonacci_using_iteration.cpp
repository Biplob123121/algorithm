#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 7;
ll fibo[N];

void fibonacci(int n)
{
    fibo[0] = 1;
    fibo[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main()
{
    int n;
    cin >> n;
    fibonacci(n);
    cout << fibo[n] << endl;
    return 0;
}