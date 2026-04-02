class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(3,-1)));
        //base for out of bounds
        for(int i=0;i<=n;i++){
            for(int cnt=0;cnt<3;cnt++){
                dp[i][m][cnt]=-1e9;
            }
        }
        for(int i=0;i<=m;i++){
            for(int cnt=0;cnt<3;cnt++){
                dp[n][i][cnt]=-1e9;
            }
        }
        // base case (last cell)
        for(int cnt = 0; cnt < 3; cnt++){
            if(coins[n-1][m-1] < 0 && cnt < 2)
                dp[n-1][m-1][cnt] = 0;
            else
                dp[n-1][m-1][cnt] = coins[n-1][m-1];
        }

        // fill DP
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                
                if(i == n-1 && j == m-1) continue;

                for(int cnt = 0; cnt < 3; cnt++){

                    int ans1 = coins[i][j] + dp[i+1][j][cnt];
                    int ans2 = coins[i][j] + dp[i][j+1][cnt];

                    int ans3 = -1e9;
                    int ans4 = -1e9;

                    if(coins[i][j] < 0 && cnt < 2){
                        ans3 = dp[i+1][j][cnt+1];
                        ans4 = dp[i][j+1][cnt+1];
                    }

                    dp[i][j][cnt] = max({ans1, ans2, ans3, ans4});
                }
            }
        }

        return dp[0][0][0];
    }
};