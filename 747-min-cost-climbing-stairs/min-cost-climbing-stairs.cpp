class Solution {
public:
    int fun(vector<int>&cost,int n,vector<int>&dp){
        if(n==0)return cost[0];
        if(n==1)return cost[1];
        if(dp[n]!=-1)return dp[n];

        int option1 = fun(cost,n-1,dp);
        int option2 = fun(cost,n-2,dp);
        return dp[n]=cost[n] + min(option1,option2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(fun(cost,n-1,dp),fun(cost,n-2,dp));
    }
};