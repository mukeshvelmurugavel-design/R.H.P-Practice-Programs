#include<bits/stdc++.h>
using namespace std;

int main(){
int n,m;
cin>>n>>m;

vector<vector<int>> adj(n+1);

for(int i=0;i<m;i++){
int a,b;
cin>>a>>b;
adj[a].push_back(b);
adj[b].push_back(a);
}

int s,t;
cin>>s>>t;

vector<int> dist(n+1,-1);
queue<int> q;

q.push(s);
dist[s]=0;

while(!q.empty()){
int u=q.front();
q.pop();

for(int v:adj[u]){
if(dist[v]==-1){
dist[v]=dist[u]+1;
q.push(v);
}
}
}

cout<<dist[t]<<endl;

return 0;
}