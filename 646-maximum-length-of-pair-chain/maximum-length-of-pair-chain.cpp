class Solution {
public:
    int solve(vector<vector<int>>&pairs,int i,int last,vector<vector<int>>&dp){
        int n=pairs.size();
        if(i==n){
            return 0;
        }
        //
        if(dp[i][last+1001]!=-1)return dp[i][last+1001];
        //take
        int ans1=0;
        if(pairs[i][0]>last)ans1=1+solve(pairs,i+1,pairs[i][1],dp);
        //dont take
        int ans2=0+solve(pairs,i+1,last,dp);
        return dp[i][last+1001]=max(ans1,ans2);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(2002,-1));
        int i=0;
        return solve(pairs,i,-1001,dp);
    }
};