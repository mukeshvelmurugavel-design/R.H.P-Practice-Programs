#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for(int i=0;i<n; i++) cin >> nums[i];
    sort(nums.begin(),nums.end());
    long long sum = 0;
    for(int i=1; i<n-1; i++) {
        long long n = nums.end()-upper_bound(nums.begin(),nums.end(),nums[i]);
        long long m = lower_bound(nums.begin(),nums.end(),nums[i]) - nums.begin();
        sum+=(n*m*1ll);
    }
    cout << sum << '\n';
}