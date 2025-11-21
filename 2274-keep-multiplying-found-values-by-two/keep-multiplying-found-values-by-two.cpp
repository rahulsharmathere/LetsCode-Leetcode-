class Solution {
public:
    bool search(vector<int>&nums,int k){
        int n=nums.size();

        int s=0;
        int e=n-1;
        while(s<=e){
            int m=s-(s-e)/2;
            if(nums[m]==k)return true;
            else if(nums[m]<k)s=m+1;
            else e=m-1;
        }
        return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        //we will use binary search
        sort(nums.begin(),nums.end());
        while(search(nums,original)){
            original=original*2;
        }
        return original;
    }
};