class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=grid[i][0];
            for(int j=1;j<m;j++){
                int len2=curr+grid[i][j];
                sum=max(sum,len2);
                if(i>0 && i<n-1 && j>0 && j<m-1)sum=max(sum,grid[i][j]);
                curr=max(grid[i][j],grid[i][j]+curr);
            }
        }
         for(int j=0;j<m;j++){
            int curr=grid[0][j];
            for(int i=1;i<n;i++){
                int len2=curr+grid[i][j];
                sum=max(sum,len2);
                if(i>0 && i<n-1 && j>0 && j<m-1)sum=max(sum,grid[i][j]);
                curr=max(grid[i][j],grid[i][j]+curr);
            }
        }
        return sum;
    }
};