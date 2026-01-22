class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //BFS:::
        vector<vector<int>>vis(n,vector<int>(m,0));
        int fresh=0;
        queue<pair<pair<int,int>,int>>q;//row,col,time
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                if(grid[i][j]==1)fresh++;
            }
        }

        int maxt=0;
        int dr[4]={0,0,1,-1};
        int dc[4]={1,-1,0,0};

        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;    
            int t=q.front().second;

            maxt=max(maxt,t);
            q.pop();

            for(int k=0;k<4;k++){
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({{nr,nc},t+1});
                }
            }

        }

        if(fresh==0)return maxt;
        return -1;


    }
};