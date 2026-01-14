class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //floor
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>>final(n,vector<int>(m,0));
        int dr[8]={-1,-1,-1,0,0,1,1,1}; 
        int dc[8]={-1,0,1,-1,1,-1,0,1}; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=img[i][j];
                int cnt=1;
                for(int k=0;k<8;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr<n && nc<m && nr>=0 && nc>=0){
                        cnt++;
                        sum+=img[nr][nc];
                    }
                }
                final[i][j]=floor(sum/cnt);
            }
        }
        return final;
    }
};