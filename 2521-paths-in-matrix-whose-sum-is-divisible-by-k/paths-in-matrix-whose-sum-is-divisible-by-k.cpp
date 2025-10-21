class Solution {
public:
    int solve(vector<vector<int>>&grid,int k,int i,int j,int n,int m,int rem,vector<vector<vector<int>>>&DP){
        int mod=1e9+7;

        if(i<0 || j<0 || i>=n || j>=m)return 0;

        rem = (rem+grid[i][j])%k;
        
        if(i==n-1 && j==m-1)return (rem%k==0);

        if(DP[i][j][rem]!=-1)return DP[i][j][rem];

        //down
        int down=solve(grid,k,i+1,j,n,m,rem,DP);
        //right
        int right=solve(grid,k,i,j+1,n,m,rem,DP);

        return DP[i][j][rem]=(down+right)%(mod);

    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(m,vector<int>(51,-1)));
        //0,0
        return solve(grid,k,0,0,n,m,0,DP);
    }
};