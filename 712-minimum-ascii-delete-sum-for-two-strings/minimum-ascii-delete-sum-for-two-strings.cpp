class Solution {
public:
    int helper(string&s1,string&s2,int i,int j,vector<vector<int>>&dp){
        if(i>=s1.size() || j>=s2.size())return 0;
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int sum;
        if (s1[i] == s2[j]) 
            sum = s1[i]+helper(s1,s2,i+1,j+1,dp);
        else 
            sum = max(helper(s1,s2,i+1,j,dp),helper(s1,s2,i,j+1,dp));
        
        return dp[i][j] = sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        //  sea       eat
        // del s     del t
        //sum->s+t->231
        int sum=0;
        vector<vector<int>>dp(n1,vector<int>(n2,INT_MAX));
        for(char c: s1) sum+=c;
        for(char c: s2) sum+=c;
        return sum-2*helper(s1, s2,0, 0,dp);

    }
};