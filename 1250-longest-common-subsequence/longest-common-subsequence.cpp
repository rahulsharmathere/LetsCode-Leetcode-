class Solution {
public:
   
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();

        int i=0;
        int j=0;

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //base:
        for(int i=0;i<n;i++){
            dp[i][m]=0;
        }
        for(int i=0;i<m;i++){
            dp[n][i]=0;
        }
        for (int i=n-1; i>=0; i--) {
            for (int j=m-1; j>=0; j--) {
                if (s1[i]==s2[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        
        return dp[0][0];

    }
};