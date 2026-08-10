class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int dp1=cost[0];
        int dp2=cost[1];
        for(int i=2;i<n;i++){
            int curr1 = dp2;
            int curr2 = dp1;
            int curr=cost[i] + min(curr1,curr2);
            dp1=dp2;
            dp2=curr;
        }
        return min(dp1,dp2);
    }
};