class Solution {
public:
    const int MOD=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        long long avail = k;
        long long cost=0;
        long long cnt=0;
        for(int i=0;i<n;i++){
            long long x=nums[i];
            if(nums[i]>avail){
                long long need = x - avail;
                long long factor = (need + k - 1) / k;

                __int128 add = (__int128)factor * (2LL * cnt + factor + 1) / 2;
                cost = (cost + (long long)(add % MOD)) % MOD;

                cnt += factor;
                avail += factor * 1LL * k;
                
            }
            avail-=nums[i];
            cost %= MOD;
        }
        return cost%MOD;
    }
};