class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& start) {
        int n = maze.size();
        int m = maze[0].size();
        vector<pair<int,int>> diff={{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> q;
        maze[start[0]][start[1]]='+';
        q.push(make_pair(start[0],start[1]));
        int steps = -1;
        while(!q.empty()) {
            steps++;
            int qsize = q.size();
            while(qsize--) {
                auto[row,col]=q.front();
                q.pop();
                if(row==0||col==0||row==n-1||col==m-1) {
                    if(!(row==start[0]&&col==start[1])) {
                        return steps;
                    }
                }
                for(auto[dx,dy] : diff) {
                    int ar = row+dx;
                    int ac = col+dy;
                    if(ar>=0&&ar<n&&ac>=0&&ac<m&&maze[ar][ac]=='.') {
                        maze[ar][ac]='+';
                        q.push(make_pair(ar,ac));
                    }
                }
            }
        }
        return -1;
    }
};