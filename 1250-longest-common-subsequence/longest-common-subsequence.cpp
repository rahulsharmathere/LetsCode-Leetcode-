class Solution {
  public:
    
    int longestCommonSubsequence(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        // int i=0;
        // int j=0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        //base
        for(int i=0;i<=n;i++){
            dp[i][m]=0;
        }
        for(int i=0;i<=m;i++){
            dp[n][i]=0;
        }
        dp[n-1][m-1]=s1[n-1]==s2[m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                //match
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
                //not match
                else dp[i][j]= 0+max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];

    }
};

