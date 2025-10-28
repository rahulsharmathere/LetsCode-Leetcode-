class Solution {
public:
    int solve(vector<vector<char>>& matrix,int n,int m, int i,int j,int &maxi,vector<vector<int>>&DP){
        if(i>=n || j>=m)return 0;
        if(DP[i][j]!=-1)return DP[i][j];
        int right=solve(matrix,n,m,i,j+1,maxi,DP);
        int diag=solve(matrix,n,m,i+1,j+1,maxi,DP);
        int down=solve(matrix,n,m,i+1,j,maxi,DP);

        if(matrix[i][j]=='1'){
            int ans = 1+min(right,min(diag,down));
            maxi=max(maxi,ans);
            return DP[i][j] = ans;
        }
        else return DP[i][j]=0;

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        int i=0;
        int j=0;
        int maxi=0;
        vector<vector<int>>DP(n,vector<int>(m,-1));
        solve(matrix,n,m,i,j,maxi,DP);
        return maxi*maxi;
    }

};