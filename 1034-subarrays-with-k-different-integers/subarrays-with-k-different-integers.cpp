class Solution {
public:
    int solve(vector<int>& nums,int k){
        //calculates no of subarays with no of diff integers <= k (atmost k)
        int n=nums.size();
        int r=0;
        int l=0;
        map<int,int>mp;
        int cnt=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }

            if(mp.size()<=k){
                cnt+=r-l+1;
            }
            r++;
        }
        return cnt;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //good ab samajh gya 
        //calculates no of subarays with no of diff integers = k
        int ans1 = solve(nums,k-1);
        int ans2 = solve(nums,k);
        int ans = ans2-ans1;
        return ans;
    }
};