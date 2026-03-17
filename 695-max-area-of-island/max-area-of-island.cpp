class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())return 0;
        if(vis[i][j] || grid[i][j]==0)return 0;
        vis[i][j]=1;
        int ans=1;
        ans+=dfs(i+1,j,grid,vis);
        ans+=dfs(i-1,j,grid,vis);
        ans+=dfs(i,j+1,grid,vis);
        ans+=dfs(i,j-1,grid,vis);

        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};