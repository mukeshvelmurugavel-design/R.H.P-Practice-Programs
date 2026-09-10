#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> diff = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int row, int col, int l, int m) {
        grid[l][m] = '0';

        for (int i = 0; i < 4; i++) {
            int ar = l + diff[i][0];
            int ac = m + diff[i][1];

            if (ar >= 0 && ar < row && ac >= 0 && ac < col && grid[ar][ac] == '1') {
                dfs(grid, row, col, ar, ac);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(grid, row, col, i, j);
                }
            }
        }

        return island;
    }
};

int main() {
    int row, col;

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    vector<vector<char>> grid(row, vector<char>(col));

    cout << "Enter the grid (0 or 1):\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    Solution obj;
    cout << "Number of Islands: " << obj.numIslands(grid) << endl;

    return 0;
}