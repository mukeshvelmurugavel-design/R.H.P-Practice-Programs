#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int longestSubstring(string s) {
        unordered_map<int, int> mp;

        int sum = 0;
        int maxi = 0;

        // Prefix sum 0 before the string starts
        mp[0] = -1;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s[i]))
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

    cout << "Enter a lowercase string: ";
    cin >> s;

    Solution obj;
    cout << "Length of longest substring with equal vowels and consonants: "
         << obj.longestSubstring(s) << endl;

    return 0;
}