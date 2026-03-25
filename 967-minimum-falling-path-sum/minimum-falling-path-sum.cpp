class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();//row
        int m=matrix[0].size();//col
        vector<vector<int>>DP(n,vector<int>(m,-1));
        //base
        for(int i=0;i<m;i++){
            DP[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+DP[i-1][j];
                int upRight=1e9;
                if(j-1>=0)upRight=matrix[i][j]+DP[i-1][j-1];
                int upLeft=1e9;
                if(j+1<m)upLeft=matrix[i][j]+DP[i-1][j+1];

                DP[i][j]=min(up,min(upLeft,upRight));
            }
        }
        int mini=INT_MAX;
        for(int i=0 ; i<m ; i++){
            mini=min(mini,DP[n-1][i]);
        }
        return mini;
    }
};