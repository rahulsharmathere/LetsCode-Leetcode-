class Solution {
public:
    int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(i==coins.size())return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        //take
        int take=1e9;
        if(amount>=coins[i])
            take=1+solve(coins,amount-coins[i],i,dp);
        
        //not take
        int nottake=solve(coins,amount,i+1,dp);

        return dp[i][amount] = min(take,nottake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int i=0;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=solve(coins,amount,i,dp);
        if(ans==1e9)return -1;
        return ans;
    }
};