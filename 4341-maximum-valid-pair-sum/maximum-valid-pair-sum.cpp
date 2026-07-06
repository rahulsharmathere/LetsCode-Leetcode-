class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        //TLE
        int n=nums.size();
        int i=0;
        int maxi=-1;
        int ans=-1;
        while(i<n){
            if(i>=k){
                maxi=max(maxi,nums[i-k]);
                ans=max(ans,nums[i]+maxi);
            }
            i++;
        }
        return ans;
    }
};