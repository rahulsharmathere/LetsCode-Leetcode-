class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //adj matrix for floyd marshil

        vector<vector<int>>matrix(n,vector<int>(n,1e8));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        matrix[i][j]=0;
                    }
                    else{
                        if(matrix[i][k]!=1e8 && matrix[k][j]!=1e8){
                            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                        }
                    }
                }
            }
        }

        int mini=INT_MAX;
        int minInd=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if((matrix[i][j]<=distanceThreshold)){
                    cnt++;
                }
            }
            if(cnt<=mini){
                minInd=i;
                mini=cnt;
            }
        }

        return minInd;

    }
};