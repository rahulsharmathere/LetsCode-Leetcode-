class Solution {
public:
    int solve(int i,vector<int>&nums,int target,vector<vector<int>>&DP){
        int n=nums.size();
        if(target==0)return 1;
        if (i >= n || target < 0) return 0; 
        
        if(DP[i][target]!=-1)return DP[i][target];
        
        long long ways = 0;
        // Always restart from 0 (to preserve order)
        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] <= target)
                ways += solve(k, nums, target - nums[k], DP);
        }

        return DP[i][target]= ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>DP(n,vector<int>(target+1,-1));
        int i=0;
        int ans=solve(i,nums,target,DP);
        return ans;
    }
};