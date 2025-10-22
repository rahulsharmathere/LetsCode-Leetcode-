class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //one robo 0,0
        //another robo 0,m-1
        vector<vector<vector<int>>>DP(n,vector<vector<int>>(m,vector<int>(m,0)));

        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(j==k){
                    DP[n-1][j][k]=grid[n-1][k];
                }else
                    DP[n-1][j][k]=grid[n-1][k]+grid[n-1][j];
            }
        }

        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int dra[9]={-1,-1,-1,0,0,0,1,1,1};
                    int drb[9]={-1,0,1,-1,0,1,-1,0,1};
                    int option=-1e8;

                    for(int k=0;k<9;k++){
                        int nj1=j1+dra[k];
                        int nj2=j2+drb[k];
                        if(nj1<0 || nj2<0 || nj1>=m || nj2>=m)continue;
                        if(j1==j2)
                            option=max(option,grid[i][j1]+DP[i+1][nj1][nj2]);
                        else
                            option=max(option,grid[i][j1]+grid[i][j2]+DP[i+1][nj1][nj2]);
                    }

                    DP[i][j1][j2]=option;

                }
            
            }
        }
        return DP[0][0][m-1];


    }
};