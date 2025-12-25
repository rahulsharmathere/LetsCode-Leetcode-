class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return -1;
        if (k == 0)
            return nums[0];
        if (k == 1)
            return n >= 2 ? nums[1] : -1;
        if (n == 1)
            return (k % 2 == 0) ? nums[0] : -1;
        int ans = *max_element(nums.begin(), nums.begin() + min(n, k - 1));
        if (k < n) {
            return max(ans, nums[k]);
        }
        return ans;
    }
};