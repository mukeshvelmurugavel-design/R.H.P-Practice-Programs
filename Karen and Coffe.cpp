#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    const int MAX = 200000;

    vector<int> diff(MAX + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> temp(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++) {
        temp[i] = temp[i - 1] + diff[i];
    }

    vector<int> prefix(MAX + 1, 0);

    for (int i = 1; i <= MAX; i++) {
        if (temp[i] >= k)
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}