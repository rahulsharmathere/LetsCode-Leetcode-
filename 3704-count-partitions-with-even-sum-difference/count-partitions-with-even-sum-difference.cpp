class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int leftSum=0;
        int ans=0;
        for(int i=0;i<n-1;i++){
            sum-=nums[i];
            leftSum+=nums[i];
            if((leftSum-sum)%2==0)ans++;
        }
        return ans;
    }
};