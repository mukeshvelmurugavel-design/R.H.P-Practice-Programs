class Solution {
public:
    int find(vector<int>& parent,int node) {
        if(parent[node]!=node) {
            parent[node]=find(parent,parent[node]);
        }
        return parent[node];
    }
    void join(vector<int>& parent, int left,int right) {
        parent[find(parent,right)]=find(parent,left);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> parent(N+1);
        for(int i=1; i<=N; i++) {
            parent[i]=i;
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(i==j) continue;
               if(isConnected[i-1][j-1]==1) {
                    join(parent,i,j);
               }
            }
        }
        int provinces=0;
        for(int i=1; i<=N; i++) {
            if(parent[i]==i) provinces++;
        }
        return provinces;
    }
};