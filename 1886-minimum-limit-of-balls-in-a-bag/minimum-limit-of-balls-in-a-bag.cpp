class Solution {
public:
    bool isPossible(int x,vector<int>&nums,int maxOps){
        int ops=0;
        for(auto it:nums){
            if(it<=x)continue;
            ops+=(it-1)/x;
            if(ops>maxOps)return false;
        }
        if(ops<=maxOps)return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOps) {
        int n=nums.size();
        //range of ans : 1....maxEle
        int maxi;
        maxi=*max_element(nums.begin(),nums.end());
        int s=1;
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s-(s-e)/2;
            if(isPossible(mid,nums,maxOps)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return ans;
    }
};