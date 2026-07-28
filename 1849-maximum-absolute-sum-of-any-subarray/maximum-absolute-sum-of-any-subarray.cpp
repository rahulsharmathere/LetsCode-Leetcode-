class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int minSum=INT_MAX;
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxSum=max(maxSum,sum);
            if(sum<0)sum=0;
        }
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            minSum=min(minSum,sum);
            if(sum>0)sum=0;
        }
        return abs(max(abs(maxSum),abs(minSum)));
    }
};