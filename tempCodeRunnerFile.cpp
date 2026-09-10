#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<pair<int,int>> v;
  while(n--){
    int x,y;
    cin>>x>>y;
    v.push_back({x,y});
    }
  sort(v.begin(),v.end(),greater<pair<int,int>>());
  int prev=0;
  vector<int> ht,time;
  for(auto [a,b]:v){
    if(b>prev){
      prev=b;
      ht.push_back(a);
      time.push_back(b);
    }
  }
  int z;
  cin>>z;
  while(z--){
    int f;
    cin>>f;
    auto it=upper_bound(time.begin(),time.end(),f);
    int idx=it-time.begin();
    cout<<ht[idx]<<endl;
  }
}