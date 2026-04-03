class Solution {
public:
    int solve(vector<vector<int>>&pairs,int i,int last,vector<vector<int>>&dp){
        int n=pairs.size();
        if(i==n){
            return 0;
        }
        //
        if(dp[i][last+1]!=-1)return dp[i][last+1];
        //take
        int ans1=0;
        if(last==-1 || pairs[i][0]>pairs[last][1])ans1=1+solve(pairs,i+1,i,dp);
       
        //dont take
        int ans2=0+solve(pairs,i+1,last,dp);
        return dp[i][last+1]=max(ans1,ans2);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        int i=0;
        return solve(pairs,i,-1,dp);
    }
};