class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum=max(sum+nums[i],nums[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};