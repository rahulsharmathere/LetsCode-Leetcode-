class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>&DP){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0 || i>=m || j>=n)return 0;
        if(DP[i][j]!=-1)return DP[i][j];
        //option1
        int up=solve(i-1,j,m,n,DP);
        //option2
        int left=solve(i,j-1,m,n,DP);
        return DP[i][j]= up+left;

    }
    int uniquePaths(int m, int n) {
        int i=m-1;
        int j=n-1;
        //m rows
        //n cols
        vector<vector<int>>DP(m,vector<int>(n));
        DP[0][0]=1;
        for(int i=0;i<n;i++)DP[0][i]=1;
        for(int i=0;i<m;i++)DP[i][0]=1;

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                int up=DP[i-1][j];
                int left=DP[i][j-1];
                DP[i][j]=up+left;
            }
        }
        return DP[m-1][n-1];

    }
};