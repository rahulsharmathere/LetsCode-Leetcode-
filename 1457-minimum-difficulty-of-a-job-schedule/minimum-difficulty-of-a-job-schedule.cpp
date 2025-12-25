class Solution {
public:
    int dp[301][11];
    int solve(vector<int>& jd,int n,int i,int d){
        if(d==1){
            int maxD=jd[i];
            for(int idx=i;idx<n;idx++){
                maxD=max(maxD,jd[idx]);
            }
            return maxD;
        }
        if(dp[i][d]!=-1)return dp[i][d];
        int maxD=jd[i];
        int final=INT_MAX;
        for(int idx=i;idx<=n-d;idx++){
            maxD=max(maxD,jd[idx]);
            int result=maxD+solve(jd,n,idx+1,d-1);
            final=min(final,result);
        }
        return dp[i][d]=final;
    }   
    int minDifficulty(vector<int>& jd, int d) {
        int n=jd.size();
        if(d>n)return -1;
        memset(dp,-1,sizeof(dp));
        return solve(jd,n,0,d);


    }
};