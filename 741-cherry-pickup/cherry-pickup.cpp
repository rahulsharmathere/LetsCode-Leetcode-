class Solution {
public:
    int dp[51][51][51][51];
    int solve(vector<vector<int>>&grid,int n,int i1,int j1,int i2,int j2){
        //out of bound
        if( i1>=n || j1>=n  || i2>=n || j2>=n)return -1e9;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1)return -1e9;
        //both at end
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1)return grid[i1][j1];//count once

        if(dp[i1][j1][i2][j2]!= -1) return dp[i1][j1][i2][j2];

        if(i1==i2 && j1==j2){
            //option1: 
            int opt1=max(solve(grid,n,i1+1,j1,i2+1,j2),solve(grid,n,i1+1,j1,i2,j2+1));
            //option2: 
            int opt2=max(solve(grid,n,i1,j1+1,i2+1,j2),solve(grid,n,i1,j1+1,i2,j2+1));

            return dp[i1][j1][i2][j2] = grid[i1][j1]+max(opt1,opt2);
    
        }
        else{
            //option1: 
            int opt1=max(solve(grid,n,i1+1,j1,i2+1,j2),solve(grid,n,i1+1,j1,i2,j2+1));
            //option2: 
            int opt2=max(solve(grid,n,i1,j1+1,i2+1,j2),solve(grid,n,i1,j1+1,i2,j2+1));
            return dp[i1][j1][i2][j2] = grid[i1][j1]+grid[i2][j2]+max(opt1,opt2);
        }
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1)return 0;
        int i1=0;
        int j1=0;
        int i2=0;
        int j2=0;
        //4D DP
        memset(dp,-1,sizeof(dp));
        int res = solve(grid,n,i1,j1,i2,j2);
        
        return max(0,res);
    }
};