class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0];
            int c1=queries[i][1];
            int r2=queries[i][2];
            int c2=queries[i][3];
            for(int j=r1;j<=r2;j++){
                mat[j][c1]+=1;
                if(c2+1<n)mat[j][c2+1]-=1;
            }
        }
        for(int j=0;j<n;j++){
            for(int k=1;k<n;k++){
                mat[j][k]+=mat[j][k-1];
            }
        }
        return mat;
    }
};