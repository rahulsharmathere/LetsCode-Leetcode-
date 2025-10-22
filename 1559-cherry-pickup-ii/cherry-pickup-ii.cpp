class Solution {
public:
    int solve(int i,int j1,int j2,int n,int m,vector<vector<vector<int>>>&DP,vector<vector<int>>&grid){
        if(j1<0 || j2<0 || j1>=m || j2>=m)return -1e8;
        if(i==n-1){
            if(j1!=j2)
                return grid[i][j1]+grid[i][j2];
            return grid[i][j1];
        }
        if(DP[i][j1][j2]!=-1)return DP[i][j1][j2];
        //total 9 combos
        int dra[9]={-1,-1,-1,0,0,0,1,1,1};
        int drb[9]={-1,0,1,-1,0,1,-1,0,1};
        int option=-1e8;
        for(int k=0;k<9;k++){
            if(j1==j2)
                option=max(option,grid[i][j1]+solve(i+1,j1+dra[k],j2+drb[k],n,m,DP,grid));
            else
                option=max(option,grid[i][j1]+grid[i][j2]+solve(i+1,j1+dra[k],j2+drb[k],n,m,DP,grid));

        }
        return  DP[i][j1][j2] = option;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //one robo 0,0
        //another robo 0,m-1
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return solve(0,0,m-1,n,m,DP,grid);
    }
};