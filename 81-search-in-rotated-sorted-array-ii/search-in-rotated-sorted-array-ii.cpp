class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int ind=-1;
        while(l<=r){
            int m=l-(l-r)/2;

            if(nums[m]==target){
                return true;
            }
            //Edge case:
            if (nums[l] == nums[m] && nums[m] == nums[r]) {
                l = l + 1;
                r = r - 1;
                continue;
            }
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && target<=nums[m]){
                    r=m-1;
                }else{
                    l=m+1;
                }
            }else{
                if(nums[r]>=target && target>=nums[m]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }

        }
        return false;
    }
};