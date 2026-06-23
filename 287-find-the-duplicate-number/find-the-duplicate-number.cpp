class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        //element 1....n
        //only one repeated number in nums
        int left=1;
        int right=n-1;
        int ans=-1;
        while(left<right){
            int mid=left-(left-right)/2;
            int cnt=0;
            for(int num:nums){
                if(num<=mid){
                    cnt++;
                }
            }
            if(cnt>mid)
                right=mid;
            else{
                ans=mid;
                left=mid+1;
            } 
                
        }
        return left;
    }
};