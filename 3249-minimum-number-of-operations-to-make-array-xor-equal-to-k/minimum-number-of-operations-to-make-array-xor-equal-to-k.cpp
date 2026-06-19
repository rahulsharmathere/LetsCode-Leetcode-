class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr = 0;
        for(int x : nums)
            xr ^= x;
        return __builtin_popcount(xr ^ k);
    }
};