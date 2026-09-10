#include <bits/stdc++.h>
using namespace std;

int main(){
int n,m;
cin>>n>>m;
vector<string> grid(n);
for(auto &row:grid) cin>>row;
queue<pair<int,int>> q;
vector<vector<bool>> vis(n,vector<bool>(m,false));
vector<vector<char>> parent(n,vector<char>(m));
int sx,sy,ex,ey;

for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid[i][j]=='A'){
sx=i;
sy=j;
}
if(grid[i][j]=='B'){
ex=i;
ey=j;
}
}
}

q.push({sx,sy});
vis[sx][sy]=true;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
char dir[]={'U','D','L','R'};

while(!q.empty()){
auto [x,y]=q.front();
q.pop();

for(int i=0;i<4;i++){
int nx=x+dx[i];
int ny=y+dy[i];

if(nx<0||nx>=n||ny<0||ny>=m)
continue;

if(vis[nx][ny]||grid[nx][ny]=='#')
continue;

vis[nx][ny]=true;
parent[nx][ny]=dir[i];
q.push({nx,ny});
}
}

if(!vis[ex][ey]){
cout<<"NO\n";
return 0;
}

string ans;
int x=ex,y=ey;

while(x!=sx||y!=sy){
char d=parent[x][y];
ans+=d;

if(d=='U') x++;
else if(d=='D') x--;
else if(d=='L') y++;
else if(d=='R') y--;
}

reverse(ans.begin(),ans.end());

cout<<"YES\n";
cout<<ans.size()<<'\n';
cout<<ans<<'\n';

return 0;
}