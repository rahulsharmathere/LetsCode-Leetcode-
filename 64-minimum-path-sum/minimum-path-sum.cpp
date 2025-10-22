class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j,int n,int m,vector<vector<int>>&DP){
        if(i==n-1 && j==m-1)return grid[i][j];
        if(i>=n || j>=m)return 1e9;

        if(DP[i][j]!=-1)return DP[i][j];
        int down= grid[i][j] + solve(grid,i+1,j,n,m,DP);
        int right= grid[i][j] + solve(grid,i,j+1,n,m,DP);

        return DP[i][j]=  min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //non -ve numbers
        //minimum path

        vector<vector<int>>DP(n,vector<int>(m,-1));
        return solve(grid,0,0,n,m,DP);
    }
};