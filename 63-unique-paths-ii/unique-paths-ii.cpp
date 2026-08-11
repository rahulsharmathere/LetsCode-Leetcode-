class Solution {
public:
    int solve(vector<vector<int>>&m,int i,int j,vector<vector<int>>&dp){
        if(i>=m.size() || j>=m[0].size())return 0;
        if(i==m.size()-1 && j==m[0].size()-1)return 1;
        if(m[i][j]==1)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        //down
        int op1=solve(m,i+1,j,dp);
        //right
        int op2=solve(m,i,j+1,dp);

        return dp[i][j]=op1+op2;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        if(mat[0][0]==1 || mat[n-1][m-1]) return 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(mat,0,0,dp);

    }
};