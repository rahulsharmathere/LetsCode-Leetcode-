class NeighborSum {
public:
    vector<vector<int>>adj;
    unordered_map<int,pair<int,int>>m;

    int l=0;
    int p=0;
    NeighborSum(vector<vector<int>>& grid) {
        adj=grid;
        l=grid.size();
        p=grid[0].size();
        for(int i=0;i<l;i++){
            for(int j=0;j<p;j++){
             m[grid[i][j]] = {i, j};
            }
        }

    }
    
    int adjacentSum(int value) {
        auto [i,j]=m[value];
        int dr[]={-1,0,1,0};
        int sum=0;
        int dc[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int  nc=j+dc[k];
            if(nr>=0&&nc>=0&&nr<l&&nc<p){
                sum+=adj[nr][nc];
            }
        }
        return sum;
        
    }
    
    int diagonalSum(int value) {
         auto [i,j]=m[value];
        int dr[]={-1,-1,1,1};
        int sum=0;
        int dc[]={-1,1,-1,1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int  nc=j+dc[k];
            if(nr>=0&&nc>=0&&nr<l&&nc<p){
                sum+=adj[nr][nc];
            }
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */