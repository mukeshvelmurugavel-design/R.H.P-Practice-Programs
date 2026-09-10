#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int getRoot(vector<int>& parent,int x){
if(parent[x]==x) return x;
return parent[x]=getRoot(parent,parent[x]);
}

void mergeSet(vector<int>& parent,int a,int b){
a=getRoot(parent,a);
b=getRoot(parent,b);

if(a!=b)
parent[a]=b;
}

void solve(){
int n,m;
cin>>n>>m;

vector<int> parent(n+1);

for(int i=0;i<=n;i++){
parent[i]=i;
}

vector<tuple<int,int,int>> roads;

while(m--){
int a,b,c;
cin>>a>>b>>c;

if(c<=0){
mergeSet(parent,a,b);
}
else{
roads.push_back({c,a,b});
}
}

sort(roads.begin(),roads.end());

ll answer=0;

for(auto [cost,a,b]:roads){
if(getRoot(parent,a)==getRoot(parent,b)){
answer+=cost;
}
else{
mergeSet(parent,a,b);
}
}

cout<<answer<<"\n";
}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

solve();

return 0;
}