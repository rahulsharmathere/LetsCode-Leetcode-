class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        //0 water
        //1 land
        int cntAns=0;
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && vis[i][j]!=1){
                    queue<pair<int,int>>q;//i,j -> node
                    q.push({i,j});
                    vis[i][j]=1;
                    bool isIt=true;
                    if(grid1[i][j]==0)isIt=false;

                    while(!q.empty()){
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        
                        for(int k=0;k<4;k++){
                            int nr=dr[k]+r;
                            int nc=dc[k]+c;
                            if(nr>=0 && nc>=0 && nr<n && nc<m && grid2[nr][nc]==1 && vis[nr][nc]==0){
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                                if(grid1[nr][nc]==0){
                                    isIt=false;
                                }
                            }
                        }
                    }
                    if(isIt)cntAns++;
                }
            }
        }
        return cntAns;
    }
};