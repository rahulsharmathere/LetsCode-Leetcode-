class Solution {
public:
    int solve(vector<int>&nums,int k){
        //to find no of subarrays with atmost k distinct integers
        // <=k
        int n=nums.size();
        int l=0;
        int r=0;
        map<int,int>mp;
        int cnt=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            if(mp.size()<=k){
                cnt+=(r-l+1);
            }

        
            r++;
        }
        return cnt;

    }
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int k=mp.size();
        mp.clear();
        //to find no of subarrays with exactly k distinct integers
        //exact k = atmost k - atmost k-1
        return solve(nums,k) - solve(nums,k-1);
    }
};