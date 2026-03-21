class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        if(n==1)return grid;
        for(int i=0;i<k/2;i++){
            int r1=x+i;
            int r2=x+k-1-i;
            for(int j=0;j<k;j++){
                int c=y+j;
                swap(grid[r1][c],grid[r2][c]);
            }
        }
        return grid;
    }
};