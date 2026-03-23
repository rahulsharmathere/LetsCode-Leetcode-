class Solution {
public:
    int solve(int k,vector<vector<int>>&grid,int n,int m,int i,int j,int rem,vector<vector<vector<int>>>&DP){
        int const MOD =1e9+7;
        if(i<0 || j<0 || i>=n || j>=m)return 0;
        rem=(rem+grid[i][j])%k;
        if(i==n-1 && j==m-1){
            return (rem%k==0);
        }
        if(DP[i][j][rem]!=-1)return DP[i][j][rem];

        int ans1=solve(k,grid,n,m,i+1,j,rem,DP);
        int ans2=solve(k,grid,n,m,i,j+1,rem,DP);

        return DP[i][j][rem]=(ans1+ans2)%MOD;

    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int i=0;
        int j=0;
        int rem=0;
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(m,vector<int>(51,-1)));
        return solve(k,grid,n,m,i,j,rem,DP);
    }
};