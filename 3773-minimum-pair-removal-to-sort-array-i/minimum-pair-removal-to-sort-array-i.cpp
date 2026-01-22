class Solution {
public:
    bool sorted(vector<int>& nums, int n) {
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        while(!sorted(nums, n)) {
            ans++;
            int mini = INT_MAX;
            int ind = -1;
            for(int i = 1; i < n; i++) {
                int sum = nums[i - 1] + nums[i];
                if(sum < mini) {
                    mini = sum;
                    ind = i;
                }
            }
            nums[ind - 1] = mini;
            for(int i = ind; i < n - 1; i++) nums[i] = nums[i + 1];
            n--;
        }
        return ans;
    }
};