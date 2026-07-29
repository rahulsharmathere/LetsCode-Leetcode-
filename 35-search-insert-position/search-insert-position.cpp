class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        int ans=nums.size();
        while(start<=end){
            int mid=start-(start-end)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                end=mid-1;
                ans=mid;
            }else{
                start=mid+1;
            }
            
        }
        return ans;
    }
};