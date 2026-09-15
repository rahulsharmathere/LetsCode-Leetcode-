class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n=nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        int freq=0;
        while(r<n){
            if(nums[r]%2==1)freq++;
            while(freq>k){
                if(nums[l]%2==1)freq--;
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        // k - (k-1)
        return solve(nums,k)-solve(nums,k-1);
    }
};