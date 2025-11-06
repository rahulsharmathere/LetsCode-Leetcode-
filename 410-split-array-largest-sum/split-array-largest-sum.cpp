class Solution {
public:
    bool isPossible(int maxSum,vector<int>&nums,int k){
        int prevsum=0;
        int cnt=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=prevsum+nums[i];
            if(sum>maxSum){
                cnt++;
                prevsum=nums[i];
            }else{
                prevsum+=nums[i];
            }

            if(cnt>k)return false;
        }
        return(cnt<=k);
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int start=*max_element(nums.begin(),nums.end());
        int end=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(start<=end){
            int mid=start-(start-end)/2;
            if(isPossible(mid,nums,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};