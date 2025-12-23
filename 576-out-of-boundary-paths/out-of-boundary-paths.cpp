class Solution {
public:
    int solve(int i,int j,int m,int n,int maxMove,vector<vector<vector<int>>>&dp){
        static const int MOD=1e9+7;
        if(maxMove<0)return 0;
        if(i<0 || j<0 || i>=m || j>=n){
            return 1;
        }
        if(dp[i][j][maxMove]!=-1)return dp[i][j][maxMove];
        //4 ways:
        long long up=solve(i-1,j,m,n,maxMove-1,dp);
        long long down=solve(i+1,j,m,n,maxMove-1,dp);
        long long left=solve(i,j-1,m,n,maxMove-1,dp);
        long long right=solve(i,j+1,m,n,maxMove-1,dp);
        return dp[i][j][maxMove] = (up+left+down+right)%MOD;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int ans=0;
        int i=startRow;
        int j=startColumn;
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        ans=solve(i,j,m,n,maxMove,dp);
        return ans;
    }
};