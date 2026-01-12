class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vmax=INT_MIN;
        int hmax=INT_MIN;
        int vmin=INT_MAX;
        int hmin=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vmax=max(vmax,i);
                    hmax=max(hmax,j);
                    vmin=min(vmin,i);
                    hmin=min(hmin,j);
                }
            }
        }
        int h=hmax-hmin+1;
        int v=vmax-vmin+1;
        return h*v;
    }
};