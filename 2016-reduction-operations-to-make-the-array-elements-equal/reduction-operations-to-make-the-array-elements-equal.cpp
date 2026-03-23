class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mini=nums[0];
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==mini)continue;
            if(nums[i]!=nums[i-1]){
                cnt++;
            }
            ans+=cnt;
        }
        return ans;
    }
};