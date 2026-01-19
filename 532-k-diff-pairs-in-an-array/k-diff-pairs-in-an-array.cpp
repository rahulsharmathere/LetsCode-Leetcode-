class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        if (k < 0) return 0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0;
        int j=1;
        
        while(j<n){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }
            else if(nums[j]-nums[i]>k){
                i++;
            }
            else{
                cnt++;
                i++;
                j++;
                while (i < n && nums[i] == nums[i - 1]) i++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }

        }
        return cnt;
    }
};