#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int root(vector<int>& p,int x){
if(p[x]==x) return x;
return p[x]=root(p,p[x]);
}

void unite(vector<int>& p,int a,int b){
a=root(p,a);
b=root(p,b);
if(a!=b) p[a]=b;
}

void solve(){
int n,m;
cin>>n>>m;

vector<int> parent(n+1);
for(int i=1;i<=n;i++){
parent[i]=i;
}

vector<pair<int,int>> edges;

for(int i=0;i<m;i++){
int a,b;
cin>>a>>b;
edges.push_back({a,b});
unite(parent,a,b);
}

vector<ll> nodes(n+1,0);
vector<ll> connections(n+1,0);

for(int i=1;i<=n;i++){
nodes[root(parent,i)]++;
}

for(auto e:edges){
connections[root(parent,e.first)]++;
}

ll answer=0;

for(int i=1;i<=n;i++){
ll possible=nodes[i]*(nodes[i]-1)/2;
answer+=possible-connections[i];
}

cout<<answer<<"\n";
}

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

solve();

return 0;
}