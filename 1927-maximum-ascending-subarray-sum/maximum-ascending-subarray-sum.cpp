class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>sums(n);
        sums[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])sums[i]=sums[i-1]+nums[i];
            else sums[i]=nums[i];
        }
        return *max_element(sums.begin(),sums.end());
    }
};