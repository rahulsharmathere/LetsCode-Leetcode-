class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>pref(n,vector<int>(m,0));
        // for(int i=0;i<n;i++){
        //     int prefix=0;
        //     for(int j=0;j<m;j++){
        //         pref[i][j]=prefix+grid[i][j];
        //         prefix+=grid[i][j];
        //     }
        // }

        int maxi=-1;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                int sum=grid[i][j]+
                grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+
                grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                maxi=max(maxi,sum);
            }
        }
        return maxi;
    }
};