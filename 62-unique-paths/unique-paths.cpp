class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&DP){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0 || i>=m || j>=n)return 0;
        if(DP[i][j]!=-1)return DP[i][j];
        //option1
        int up=solve(i-1,j,m,n,DP);
        //option2
        int left=solve(i,j-1,m,n,DP);
        return DP[i][j]= up+left;

    }
    int uniquePaths(int m, int n) {
        int i=m-1;
        int j=n-1;
        //m rows
        //n cols
        vector<vector<int>>DP(m,vector<int>(n,-1));
        return solve(i,j,m,n,DP);
    }
};