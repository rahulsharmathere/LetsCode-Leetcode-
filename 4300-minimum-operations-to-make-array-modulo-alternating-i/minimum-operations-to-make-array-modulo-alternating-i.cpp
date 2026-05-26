class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = INT_MAX;
        for (int x = 0; x < k; x++) {
            for (int y = 0; y < k; y++) {
                if (x == y) continue;
                int cost = 0;
                for (int i = 0; i < nums.size(); i++) {
                    int cur = nums[i] % k;
                    int target = (i % 2 == 0 ? x : y);
                    int d = abs(cur - target);
                    cost += min(d, k - d);
                }
                ans = min(ans, cost);
            }
        }
        return ans;
    }
};