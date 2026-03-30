class Solution {
  public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        int n=s1.size();
        int m=s2.size();
        if(i==n-1 && m==n-1){
            return (s1[i]==s2[j]);
        }
        if(i>=n || j>=m)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        //match
        if(s1[i]==s2[j])return dp[i][j]=1+solve(s1,s2,i+1,j+1,dp);
        //not match
        return dp[i][j]= 0+max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    }
    int longestCommonSubsequence(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        int i=0;
        int j=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(s1,s2,i,j,dp);
    }
};

