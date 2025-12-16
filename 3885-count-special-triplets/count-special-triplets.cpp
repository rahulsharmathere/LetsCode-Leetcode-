class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        const int MOD = 1e9 + 7;
        vector<long long>rightFreq(1e5+1,0);
        vector<long long>leftFreq(1e5+1,0);
        for(int i=0;i<n;i++){
            rightFreq[nums[i]]++; 
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long val=2LL*nums[i];
            rightFreq[nums[i]]--;
            if (val <= 100000) {
                ans = (ans + leftFreq[val] * rightFreq[val]) % MOD;
            }
            leftFreq[nums[i]]++;
        }
        return ans;
    }
};