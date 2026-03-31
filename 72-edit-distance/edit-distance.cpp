class Solution {
  public:
    // Function to compute the edit distance between two strings
    int solve(string& s1,string& s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size()){
            return s2.size()-j; //for rest of the characters
        }
        if(j==s2.size()){
            return s1.size()-i; //for rest of the characters
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        if(s1[i]==s2[j]){//matching character move ahead
            ans=0+solve(s1,s2,i+1,j+1,dp);
        }
        else{
            ans=1+solve(s1,s2,i+1,j,dp);//delete that char
            ans=min(ans,1+solve(s1,s2,i+1,j+1,dp));//replace that char
            ans=min(ans,1+solve(s1,s2,i,j+1,dp));// insert that char
        }
        return dp[i][j]=ans;
        
    }
    int minDistance(string s1, string s2) {
        // code here
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(s1,s2,0,0,dp);
    }
};