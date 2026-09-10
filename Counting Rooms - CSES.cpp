#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> diff={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(vector<vector<char>>& mat,int row,int col,int l,int m) {
        mat[l][m]='#';
        for(int i = 0 ;i<4;i++) {
            int ar = l + diff[i][0];
            int ac = m + diff[i][1];
            if(ar>=0&&ar<row&&ac>=0&&ac<col&&mat[ar][ac]=='.') {
                dfs(mat,row,col,ar,ac);
            }
        }
 
    }
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    int rooms= 0;
    for(int i=0; i<n;i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j]=='.') {
                rooms++;
                dfs(mat,n,m,i,j);
            }
        }
    }
    cout << rooms << '\n';
}