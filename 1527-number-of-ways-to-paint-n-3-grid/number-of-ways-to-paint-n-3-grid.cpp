
class Solution {
public:
    int MOD=1e9+7;
    long long helper(int r,int n,int prev,vector<vector<int>>&dp){
        if(r==n)return 1;
        if(dp[r][prev]!=-1)return dp[r][prev];
        //if prev=1, now 0 else opposite
        long long option=0;
        if(prev==0){ // ABA
            option=(3*helper(r+1,n,0,dp) + 2*helper(r+1,n,1,dp))%MOD;
        }else{ // ABC
            option=(2*helper(r+1,n,0,dp) + 2*helper(r+1,n,1,dp))%MOD;
        }
        return dp[r][prev]=option;

    }
    int numOfWays(int n) {
        //possible ways:
        
        //aba -> aba bab aca cac bcb cbc
        //abc -> abc acb bac bca cab cba
        vector<vector<int>>dp(n,vector<int>(2,-1));
        long long ans1=6*helper(1,n,0,dp);
        long long ans2=6*helper(1,n,1,dp);
        return (ans1+ans2)%MOD;
    }
};