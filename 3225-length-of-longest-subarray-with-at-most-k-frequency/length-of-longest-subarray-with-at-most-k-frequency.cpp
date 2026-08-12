class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        //longest good subarray
        unordered_map<int,int>mp;
        
        int l=0;
        int r=0;
        int len=INT_MIN;
        while(r<n){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                l++;
            }
            len=max(len,r-l+1);
            r++;
        }
        return len;

    }
};