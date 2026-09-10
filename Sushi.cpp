#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> res(n);
    vector<int> res1(m);

    for (int i = 0; i < n; i++)
        cin >> res[i];

    for (int j = 0; j < m; j++)
        cin >> res1[j];

    sort(res.begin(), res.end());
    sort(res1.begin(), res1.end());

    int i = n - 1;
    int j = m - 1;
    int cnt = 0;

    while (i >= 0 && j >= 0) {
        if (res1[j] <= 2 * res[i]) {
            i--;
            j--;
            cnt++;
        } else {
            j--;
        }
    }

    cout << cnt << '\n';
}

int main() {
    solve();
    return 0;
}