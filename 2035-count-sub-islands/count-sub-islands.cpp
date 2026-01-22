class Solution {
public:
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,vector<vector<int>>&vis,int r,int c,bool& isIt,int &cntAns){
        int n=grid2.size();
        int m=grid2[0].size();
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid2[nr][nc] == 1 && vis[nr][nc] == 0){
                vis[nr][nc] = 1;
                dfs(grid1,grid2,vis,nr,nc,isIt,cntAns);
                if(grid1[nr][nc] == 0){
                    isIt = false;
                }
                
            }
        }

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        //0 water
        //1 land
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        int cntAns=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && vis[i][j]!=1){
                    bool isIt=true;
                    if(grid1[i][j] == 0) isIt = false;
                    dfs(grid1,grid2,vis,i,j,isIt,cntAns);
                    if(isIt)cntAns++;
                }
            }
        }
        return cntAns;
    }
};