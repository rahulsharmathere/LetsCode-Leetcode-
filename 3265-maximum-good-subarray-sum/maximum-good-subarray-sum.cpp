class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        long long res = LLONG_MIN;
        unordered_map<long long, long long> mp;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
            if(mp.find(nums[i]-k)!=mp.end())
               res=max(res,prefix[i+1]-mp[nums[i]-k]);
            if(mp.find(nums[i]+k)!=mp.end())
               res=max(res,prefix[i+1]-mp[nums[i]+k]);   
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=prefix[i];
            mp[nums[i]]=min(mp[nums[i]],prefix[i]);    
        }
        return res == LLONG_MIN ? 0 : res;
    }
};