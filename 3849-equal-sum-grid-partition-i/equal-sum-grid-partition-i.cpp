class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }
        long long prevSum=0;
        for(int j=0;j<m;j++){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            if((prevSum+sum)*2 == total)return true;
            prevSum+=sum;
        }
        prevSum=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            if((prevSum+sum)*2 == total)return true;
            prevSum+=sum;
        }
        return false;
            
    }
};