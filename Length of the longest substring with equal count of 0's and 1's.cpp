#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubstring(string s) {
        unordered_map<int, int> mp;

        int sum = 0;
        int maxi = 0;

        // Prefix sum 0 occurs before the string starts
        mp[0] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1')
                sum += 1;
            else
                sum -= 1;

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxi;
    }
};

int main() {
    string s;

    cout << "Enter binary string: ";
    cin >> s;

    Solution obj;
    cout << "Length of longest substring with equal 0's and 1's: "
         << obj.longestSubstring(s) << endl;

    return 0;
}