#include <iostream>
using namespace std;

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int dp[3][3];

    // Copy first row
    for (int j = 0; j < 3; j++)
        dp[0][j] = a[0][j];

    // Fill DP table
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int left = (j > 0) ? dp[i-1][j-1] : 0;
            int up = dp[i-1][j];
            int right = (j < 2) ? dp[i-1][j+1] : 0;

            dp[i][j] = a[i][j] + max(left, max(up, right));
        }
    }

    int ans = 0;
    for (int j = 0; j < 3; j++)
        ans = max(ans, dp[2][j]);

    cout << "Maximum Value = " << ans;

    return 0;
}