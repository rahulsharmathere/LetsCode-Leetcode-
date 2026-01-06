class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;//ele,freq
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxi=INT_MIN;
        int cnt=1;
        for(auto it:mp){
            if(it.second>=maxi){
                if(it.second==maxi){
                    cnt++;
                }else{
                    cnt=1;
                }
                maxi=it.second;
            }
        }
        return cnt*maxi;
    }
};