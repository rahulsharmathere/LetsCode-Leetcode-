class Solution {
public:
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
        if(k==s3.size()){
            return (i==s1.size() && j==s2.size());
        }

        if(dp[i][j][k]!=-1)return dp[i][j][k];

        bool ans1=false;
        if(s1[i]==s3[k])ans1=solve(s1,s2,s3,i+1,j,k+1,dp);
        bool ans2=false;
        if(s2[j]==s3[k])ans2=solve(s1,s2,s3,i,j+1,k+1,dp);

        return dp[i][j][k]=(ans1||ans2);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();
        int n2=s2.size();
        int n3=s3.size();
        int i=0;
        int j=0;
        int k=0;
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,-1)));
        return solve(s1,s2,s3,i,j,k,dp);

    }
};