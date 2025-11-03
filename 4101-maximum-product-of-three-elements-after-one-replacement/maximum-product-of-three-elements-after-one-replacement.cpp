class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        long long secmaxi=0;
        for (auto x : nums) {
            long long dig = abs(x);
            if (dig >= maxi){ 
                secmaxi = maxi;
                maxi = dig; 
            }
            else if (dig > secmaxi){
                secmaxi = dig;
            }
        }
        return 100000LL*maxi*secmaxi;
    }
};