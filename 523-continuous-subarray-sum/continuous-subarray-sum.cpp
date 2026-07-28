class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0] = -1; 
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            if(mp.find(prefix%k)!=mp.end()){
                if(i-mp[prefix%k]>=2)return true;
            }else{
                mp[prefix%k]=i;
            }

        }
        return false;
    }
};