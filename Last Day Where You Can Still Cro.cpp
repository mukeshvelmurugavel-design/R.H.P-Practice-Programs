class Solution {
public:
    int find(vector<int>& parent,int node) {
        if(parent[node]!=node) {
            parent[node]=find(parent,parent[node]);
        }
        return parent[node];
    }
    void join(vector<int>& parent,int row,int col) {
        parent[find(parent,col)]=find(parent,row);
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        const vector<vector<int>> diff = {{-1,0},{1,0},{-1,-1},{1,1},{0,1},{0,-1},{1,-1},{-1,1}};
        vector<bool> water(row*col+2,true);
        vector<int> parent(row*col+2,0);
        for(int i=0; i<row*col+2; i++) {
            parent[i]=i;         
        }
        int days = 0;
        for(int i=0; i<cells.size(); i++) {
            int R = cells[i][0];
            int C = cells[i][1];
            R--;
            C--;
            water[R*col+C+1]=false;
            for(int i=0; i<8; i++) {
                int ar = R+diff[i][0];
                int ac = C+diff[i][1];
            if(ar>=0&&ar<row&&ac>=0&&ac<col&&!water[ar*col+ac+1]) {
               
                    join(parent,R*col+C+1,ar*col+ac+1);
            }
            }
            if(C==0) join(parent,0,R*col+C+1);
            if(C==col-1) join(parent,row*col+1,R*col+C+1);
            if(find(parent,0)==find(parent,row*col+1)) return days;
            days++;
        }
        return days;
    }
};