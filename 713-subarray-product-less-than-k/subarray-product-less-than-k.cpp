class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n=nums.size();
        int l=0;
        int r=0;
        long long product=1;
        int cnt=0;
        while(r<n){
            product=product*nums[r];
            while(product>=k){
                product/=nums[l];
                l++;
            }
            cnt+=(r-l+1);
            
            r++;
        }
        return cnt;
    }
};