#include <iostream>
#include <vector>

using namespace std;

bool canObtain1000Marks(vector<int>& marks, int n, int target) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: With 0 marks, Zarif can always obtain 0 marks.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= marks[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - marks[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> marks(N);
        for (int i = 0; i < N; i++) {
            cin >> marks[i];
        }

        if (canObtain1000Marks(marks, N, M)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
