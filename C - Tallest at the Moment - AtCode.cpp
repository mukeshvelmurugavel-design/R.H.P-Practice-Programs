void solve()
{
    int n;
    cin >> n;
    vi height(n);
    vi time(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i] >> time[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        height[i] = max(height[i + 1], height[i]);
    }
        int q;
    cin >> q;
    vi query(q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        int ind = upper_bound(time.begin(), time.end(), x) - time.begin();
        cout << height[ind] << '\n';
    }
}
