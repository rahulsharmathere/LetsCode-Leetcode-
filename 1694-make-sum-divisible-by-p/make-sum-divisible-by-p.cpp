class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        
        for (int x : nums) total += x;
        
        int target = total % p;
        if (target == 0) return 0;
        
        unordered_map<int, int> mp;
        mp[0] = -1;
        long long prefix = 0;
        int mini = n;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int curr = prefix % p;
            int need = (curr - target + p) % p;
            if (mp.find(need) != mp.end()) {
                mini = min(mini, i - mp[need]);
            }
            mp[curr] = i;
        }
        return (mini == n) ? -1 : mini;
    
    }
};