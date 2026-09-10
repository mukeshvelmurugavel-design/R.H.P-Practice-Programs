class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshOranges = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
                if(grid[i][j]==1) {
                    freshOranges++;
                }
            }
        }
        int minutes = -1;
          if(freshOranges==0) return 0;
        if(q.empty()) return -1;
        vector<pair<int,int>> dirs = {{-1,0},{0,1},{0,-1},{1,0}};
        while(!q.empty()) {
            int qsize=q.size();
            while(qsize--) {
                auto[x,y]=q.front();
                q.pop();
                for(auto[dx,dy] : dirs) {
                    int ar = x + dx;
                    int ac = y + dy;
                    if(ar>=0&&ar<m&&ac>=0&&ac<n&&grid[ar][ac]==1) {
                        grid[ar][ac]=2;
                        freshOranges--;
                        q.push({ar,ac});
                    }
                }
            }
            minutes++;
        }
        if(freshOranges==0) return minutes;
        return -1;
    }
};