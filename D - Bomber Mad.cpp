#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	int R,C,K;
	cin>>R>>C>>K;
	vector<string> g(R);
	queue<pair<int,int>> q;
	vector<bool> br(R,false),bc(C,false);
	for(int row=0;row<R;row++){
		cin>>g[row];
	}
	for(int row=0;row<R;row++){
		for(int col=0;col<C;col++){
			if(g[row][col]=='#'){
				br[row]=bc[col]=true;
				}
			
			
		}
	}
	vector<vector<bool>> vis(R,vector<bool>(C,false));
	for(int row=0;row<R;row++){
		for(int col=0;col<C;col++){
			if(!br[row]&&!bc[col]){
				q.push(make_pair(row,col));
				vis[row][col]=true;
			}
		}
	}
	int hops=0,cellcnt=0;
	int diff[5]={0,1,0,-1,0};
	while(!q.empty()&&hops<=K){
		hops++;
		int qsize=q.size();
		cellcnt+=qsize;
		while(qsize--){
			auto[row,col]=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int ar=row+diff[i];
				int ac=col+diff[i+1];
				if(ar>=0&&ar<R&&ac>=0&&ac<C&&!vis[ar][ac]&&g[ar][ac]=='.'){
					q.push(make_pair(ar,ac));
					vis[ar][ac]=true;
				}
			}
		}
	}
	cout<<cellcnt<<endl;
	
}