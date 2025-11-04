class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=n-1;
        sort(nums.begin(),nums.end());
        int index;
        while(start<=end){
            int mid=start-(start-end)/2;
            if(nums[mid]>=k){
                index=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return index;
    }
};