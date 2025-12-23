class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       


        static const int MOD=1e9+7;
        vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+2,vector<int>(maxMove+1,0)));
        for(int i = 0;i< m + 2;i++){
            for(int k = 0;k < maxMove + 1;k++){
                dp[i][0][k] = 1;
                dp[i][n + 1][k] = 1;
            }
        }
        for(int j = 0;j < n + 2;j++){
            for(int k = 0;k < maxMove + 1;k++){
                dp[0][j][k] = 1;
                dp[m + 1][j][k] = 1;
            }
        }

        for(int k=1;k<maxMove+1;k++){
            for(int i=1;i<m+1;i++){
                for(int j=1;j<n+1;j++){
                    
                    long long ans=0;
                    //up
                    ans+=dp[i+1][j][k-1];
                    ans%=MOD;
                    //down
                    ans+=dp[i-1][j][k-1];
                    ans%=MOD;
                    //left
                    ans+=dp[i][j-1][k-1];
                    ans%=MOD;
                    // right
                    ans+=dp[i][j+1][k-1];
                    ans%=MOD;

                    dp[i][j][k]=ans;
                }
            }
        }

        return dp[startRow+1][startColumn+1][maxMove];
        
    }
};