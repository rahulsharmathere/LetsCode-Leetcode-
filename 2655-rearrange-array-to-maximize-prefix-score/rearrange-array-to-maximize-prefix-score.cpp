class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int cnt=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            if(sum<=0)break;
            cnt++;
        }
        return cnt;
    }
};