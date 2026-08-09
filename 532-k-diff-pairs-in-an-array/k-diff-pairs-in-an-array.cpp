class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        if (k < 0) return 0;

        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        for(auto &[ele,freq]:mp){
            if(k==0){
                if(freq>1){
                    cnt++;
                }
            }else{
                if (mp.count(ele + k)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};