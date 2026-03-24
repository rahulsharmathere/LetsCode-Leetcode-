class Solution {
public:
    int solve(vector<int>&nums,int i,bool taken,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][taken]!=-1)return dp[i][taken];
        //take
        int ans1=0;
        if(!taken)
            ans1=nums[i]+solve(nums,i+1,true,dp);
        // leave
        int ans2=solve(nums,i+1,false,dp);

        return dp[i][taken]=max(ans1,ans2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        bool flag=false;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(nums,i,flag,dp);
    }
};