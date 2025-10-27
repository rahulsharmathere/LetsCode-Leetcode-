class Solution {
public:
    int solve(vector<int>&DP,vector<int>&coins,int amount ){
        if(amount==0)return 0;
        if(amount<0)return INT_MAX;
        if(DP[amount]!=-1)return DP[amount];
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=solve(DP,coins,amount-coins[i]);
            if(ans!=INT_MAX)
                mini=min(mini,1+ans);
        }
        return DP[amount]=mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>DP(amount+1,-1);
        int ans=solve(DP,coins,amount);
        if(ans!=INT_MAX)
            return ans;
        return -1;
    }
};