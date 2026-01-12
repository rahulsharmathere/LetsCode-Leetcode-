class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<long long>cnts;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cnt++;
            else{
                if(cnt)cnts.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt)cnts.push_back(cnt);
        
        long long ans=0;
        for(auto n:cnts){
            ans+=(n*(n+1))/2;
        }
        return ans;
    }
};