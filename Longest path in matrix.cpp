#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c) {
        if (dp[r][c] != -1)
            return dp[r][c];

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 1;

        for (auto &d : directions) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                matrix[nr][nc] > matrix[r][c]) {

                ans = max(ans, 1 + dfs(matrix, dp, nr, nc));
            }
        }

        dp[r][c] = ans;
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        int longest = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                longest = max(longest, dfs(matrix, dp, i, j));
            }
        }

        return longest;
    }
};

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> matrix(rows, vector<int>(cols));

    cout << "Enter the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    cout << "Longest Increasing Path Length: "
         << obj.longestIncreasingPath(matrix) << endl;

    return 0;
}