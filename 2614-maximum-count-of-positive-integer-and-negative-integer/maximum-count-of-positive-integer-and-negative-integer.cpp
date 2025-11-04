class Solution {
public:
    int bs(vector<int>&nums,int tar){
        int start=0;
        int n=nums.size();
        int end=n-1;
        int index=n;
        int mid = (start + end) / 2;
        while(start<=end){
            mid = (start + end) / 2;
            if(nums[mid]<tar){
                start=mid+1;
            }
            else{
                index=mid;
                end=mid-1;
            }
        }
        return index;
    }
    int maximumCount(vector<int>& nums) {
        //TRY and find index of 0 or next greatest element
        int n=nums.size();
        int noNeg=bs(nums,0);
        int noPos=n-bs(nums,1);

        return max(noNeg,noPos);
    }
};