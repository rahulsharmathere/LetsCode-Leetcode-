class Solution {
public:
    int solve(vector<int>& nums, int index, vector<int>& dp) {
        int n = nums.size();

        if (index >= n - 1) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int mini = INT_MAX;

        for (int i = 1; i <= nums[index]; i++) {
            int next = index + i;

            if (next < n) {
                int jumps = solve(nums, next, dp);

                if (jumps != INT_MAX) {
                    mini = min(mini, 1 + jumps);
                }
            }
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(nums, 0, dp);
    }
};