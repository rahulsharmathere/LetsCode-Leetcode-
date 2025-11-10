class Solution {
public:
    int solve(vector<vector<int>>&grid,int k,int i,int j,vector<vector<vector<int>>>&DP){
        int n=grid.size();
        int m=grid[0].size();
        if( i>=n || j>=m)return INT_MIN;

        int cost = (grid[i][j] == 0 ? 0 : 1);
        int score = grid[i][j];

        if (k < cost) return INT_MIN;         
        if (i == n - 1 && j == m - 1) {
            return (k >= cost ? score : INT_MIN);
        }
        if(DP[i][j][k]!=-1)return DP[i][j][k];
        //options
        int option1 = solve(grid,k-cost,i+1,j,DP);
        int option2 = solve(grid,k-cost,i,j+1,DP);

        int ans=max(option1,option2);
        if(ans==INT_MIN)return DP[i][j][k]=INT_MIN;
        return DP[i][j][k]=grid[i][j]+ans; 

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        //0,0 -> n-1,m-1
        //right , down

        //max score , cost<=k ...... -1
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int i=0;
        int j=0;
        int ans=solve(grid,k,i,j,DP);
        if(ans==INT_MIN)return -1;
        return ans;
    }
};