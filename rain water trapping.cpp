#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n);
        vector<int> right(n);

        int maxsize = -1;

        // Left maximum array
        for (int i = 0; i < n; i++) {
            if (maxsize < height[i]) {
                maxsize = height[i];
            }
            left[i] = maxsize;
        }

        // Right maximum array
        maxsize = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (maxsize < height[i]) {
                maxsize = height[i];
            }
            right[i] = maxsize;
        }

        // Calculate trapped water
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += min(left[i], right[i]) - height[i];
        }

        return total;
    }
};

int main() {
    int n;

    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;
    cout << "Total trapped rainwater: " << obj.trap(height) << endl;

    return 0;
}