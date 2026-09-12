#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define ll unsigned long long int
using namespace std;

void solve(){
    int N, K; cin >> N >> K;
    vector<int> arr(N), cnt(N+N+N+1, 0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int ans = 0;
    for(int val = 1; val <= N+N; val++){
        int curr = val;
        while(cnt[curr] > K){
            cnt[curr+1] += cnt[curr]-1;
            cnt[curr] = 1;
            curr++;
        }
        ans = max(ans, curr-val);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}