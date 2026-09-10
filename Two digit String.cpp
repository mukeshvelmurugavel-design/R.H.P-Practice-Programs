#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string n1, n2;
        cin >> n1 >> n2;
        vector<vector<int>> dp(n1.length()+1, vector<int>(n2.length()+1, 0));
        int total = 0;
        vector<int> lff(n1.length());
        vector<int> rff(n2.length());
        for (int i = 0; i < n1.length(); i++) {
            total = (total+(n1[i] - '0'))%10;
            lff[i] = total;
        }
        total = 0;
        for (int j = 0; j < n2.length(); j++) {
            total = (total+(n2[j] - '0')) % 10;
            rff[j] = total;
        }
        if(lff[n1.length()-1]!=rff[n2.length()-1]) {
            cout << -1 << '\n';
            return;
        }
        for (int i = 1; i <= n1.length(); i++) {
            for (int j = 1; j <= n2.length(); j++) {
                if(lff[i-1]==rff[j-1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[n1.length()][n2.length()] << '\n';
    }
}