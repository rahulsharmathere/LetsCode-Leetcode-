class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>DP(n);
        DP[0]=nums[0];
        DP[1]=max(nums[0],nums[1]);
        for(int ind=2;ind<n;ind++){
            //take:
            int opt1=INT_MIN;
            if(ind-2>=0)
                opt1=nums[ind]+DP[ind-2];
            //leave
            int opt2=DP[ind-1];

            DP[ind]=max(opt1,opt2);
        }
        return DP[n-1];

    }
};