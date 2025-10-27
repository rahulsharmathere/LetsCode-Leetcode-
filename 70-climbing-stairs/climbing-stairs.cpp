class Solution {
public:
    int climbStairs(int n) {
        //n steps to reach top
        if(n<=1)return 1;
        // DP[0]=1;
        // DP[1]=1;
        int prev2=1;
        int prev1=1;
        int curr=0;
        for(int ind=2;ind<=n;ind++){
            int option1=prev1;
            int option2=prev2;
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
        
    }
};