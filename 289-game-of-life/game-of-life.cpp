class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        //1 -> 0 if neighbours alive < 2
        //1 -> 0 if neighbours alive > 3
        //0 -> 1 if neighbours alive == 3
        int drow[8]={1,1,-1,-1,0,0,1,-1};
        int dcol[8]={1,-1,-1,1,1,-1,0,0};
        vector<vector<int>>ans=board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cntLive=0;
                for(int k=0;k<8;k++){
                    int nr=i+drow[k];
                    int nc=j+dcol[k];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==1){
                        cntLive++;
                    }
                }
                if(board[i][j]==1){
                    if(cntLive < 2 || cntLive > 3)
                        ans[i][j] = 0;   
                    else
                        ans[i][j] = 1;
                }
                else {
                    if(cntLive==3)
                        ans[i][j]=1;
                }
            }

        }
        board=ans;
    }   
};