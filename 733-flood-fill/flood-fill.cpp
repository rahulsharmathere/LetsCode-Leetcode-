class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&image,int color,int original,vector<vector<int>>&vis){
        int n=image.size();
        int m=image[0].size();
        vis[i][j]=1;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        image[i][j]=color;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]!=1 && image[nr][nc]==original){
                dfs(nr,nc,image,color,original,vis);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int original=image[sr][sc];
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        dfs(sr,sc,image,color,original,vis);
        return image;
    }
};