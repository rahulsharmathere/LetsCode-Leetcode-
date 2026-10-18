class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN, mn = INT_MAX;
        int l = -1, r = -1;

        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            if (nums[i] < mx)
                r = i;
        }

        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            if (nums[i] > mn)
                l = i;
        }

        return (l == -1) ? 0 : r - l + 1;
    }
};