class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>sum(n,vector<int>(m,-1));
        sum[0][0]=grid[0][0];
        int cnt=0;
        if(grid[0][0]<=k)cnt++;
        for(int i=1;i<n;i++){
            sum[i][0]=sum[i-1][0]+grid[i][0];
            if(sum[i][0]<=k)cnt++;
        }
        for(int i=1;i<m;i++){
            sum[0][i]=sum[0][i-1]+grid[0][i];
            if(sum[0][i]<=k)cnt++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                sum[i][j]=grid[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
                if(sum[i][j]<=k)cnt++;
            }
        }
        return cnt;


    }
};