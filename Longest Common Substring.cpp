#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int a = s1.length();
    int b = s2.length();

    vector<vector<int>> grid(a + 1, vector<int>(b + 1, 0));

    int maxi = 0;

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                grid[i][j] = grid[i - 1][j - 1] + 1;
                maxi = max(maxi, grid[i][j]);
            } else {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
            }
        }
    }

    cout << maxi << endl;

    return 0;
}