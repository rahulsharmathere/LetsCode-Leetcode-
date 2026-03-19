class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>cntx(n,vector<int>(m,0));
        vector<vector<int>>cnty(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    cntx[i][j]+=cntx[i-1][j];
                    cnty[i][j]+=cnty[i-1][j];
                }
                if(j>0){
                    cntx[i][j]+=cntx[i][j-1];
                    cnty[i][j]+=cnty[i][j-1];
                }
                if(i>0 && j>0){
                    cntx[i][j]-=cntx[i-1][j-1];
                    cnty[i][j]-=cnty[i-1][j-1];
                }

                if(grid[i][j]=='X') cntx[i][j]++;
                if(grid[i][j]=='Y') cnty[i][j]++;

                if(cntx[i][j]>=1 && cntx[i][j]==cnty[i][j]) ans++;
            }
        }
        return ans;
    }
};