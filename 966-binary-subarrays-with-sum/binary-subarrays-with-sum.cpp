class Solution {
public:
    int solve(vector<int>&nums,int goal){
        int n=nums.size();
        if (goal < 0) return 0;
        int l=0;
        int r=0;
        int cnt=0;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        return (solve(nums,goal)-solve(nums,goal-1));
    }
};