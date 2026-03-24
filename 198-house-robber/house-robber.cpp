class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        //base
        dp[n][0]=0;
        dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                //take
                int ans1=0;
                if(!j)
                    ans1=nums[i]+dp[i+1][1];
                // leave
                int ans2=dp[i+1][0];

                dp[i][j]=max(ans1,ans2);
            }
        }
        return dp[0][0];

    }
};