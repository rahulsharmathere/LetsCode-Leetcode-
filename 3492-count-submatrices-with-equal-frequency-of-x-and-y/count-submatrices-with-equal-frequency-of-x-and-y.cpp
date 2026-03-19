class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>cntx(n,vector<int>(m,0));
        vector<vector<int>>cnty(n,vector<int>(m,0));
        if(grid[0][0]=='X')cntx[0][0]=1;
        if(grid[0][0]=='Y')cnty[0][0]=1;

        for(int i=1;i<m;i++){
            cntx[0][i]=cntx[0][i-1];
            cnty[0][i]=cnty[0][i-1];
            if(grid[0][i]=='X')cntx[0][i]++;
            if(grid[0][i]=='Y')cnty[0][i]++;
            if(cntx[0][i]>=1 && cnty[0][i]==cntx[0][i])ans++;
        }
        for(int i=1;i<n;i++){
            cntx[i][0]=cntx[i-1][0];
            cnty[i][0]=cnty[i-1][0];
            if(grid[i][0]=='X')cntx[i][0]++;
            if(grid[i][0]=='Y')cnty[i][0]++;
            if(cntx[i][0]>=1 && cnty[i][0]==cntx[i][0])ans++;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                cntx[i][j]=cntx[i-1][j]+cntx[i][j-1]-cntx[i-1][j-1];
                cnty[i][j]=cnty[i-1][j]+cnty[i][j-1]-cnty[i-1][j-1];
                if(grid[i][j]=='X')cntx[i][j]++;
                if(grid[i][j]=='Y')cnty[i][j]++;
                if(cntx[i][j]>=1 && cnty[i][j]==cntx[i][j])ans++;
            }
        }
        return ans;
    }
};