class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(auto num:nums){
            if(num==0)cnt++;
        }   
        int ans=0;
        int j=n-1;
        for(int i=0 ; i<cnt ; i++){
            if(nums[j]!=0)ans++;
            j--;
        }
        return ans;
    }
};