#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#define ll long long int
using namespace std;

struct bus{
    ll lt, rt;
    double time;
    friend bool operator<(bus a, bus b){
        if(a.lt != b.lt){
            return a.lt < b.lt;
        }
        return a.time < b.time;
    }
}buses[200000];

void solve(){
    int B, P, L, bsp, psp, ppos;
    cin >> B >> P >> L >> bsp >> psp;
    for(int i = 0; i < B; i++){
        cin >> buses[i].lt >> buses[i].rt;
        buses[i].time = (double) (buses[i].rt + buses[i].lt) / bsp + (double) (L-buses[i].rt) / (double) psp;
    }
    sort(buses, buses+B);
    for(int i = 0; i < B-1; i++){
        buses[i+1].time = min(buses[i+1].time, buses[i].time);
    }
    double ans;
    for(int i = 0; i < P; i++){
        cin >> ppos;
        ans = (double) (L-ppos) / (double) psp;
        int blt = 0, brt = B;
        bool found = false;
        while(blt < brt){
            int mid = (blt+brt)/2;
            if(buses[mid].lt <= ppos){
                found = true;
                if(blt == mid) break;
                blt = mid;
            }else{
                brt = mid;
            }
        }
        if(found){
            ans = min(ans, buses[blt].time);
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(11);
    solve();
}
