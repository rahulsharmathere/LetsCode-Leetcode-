class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int rows=board.size();
        int cols=board[0].size();
       
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if((i==rows-1||j==cols-1||i==0||j==0)&&board[i][j]=='O'){
                    q.push({i,j});
                    board[i][j]='#';
                }
            }
        }
        while(!q.empty()){
           int row=q.front().first;
           int col=q.front().second;
           q.pop();
           if(row+1<rows && board[row+1][col]=='O'){
            q.push({row+1,col});
            board[row+1][col]='#';

           }
            if(col+1<cols && board[row][col+1]=='O'){
            q.push({row,col+1});
            board[row][col+1]='#';

           }
            if(row-1>0 && board[row-1][col]=='O'){
            q.push({row-1,col});
            board[row-1][col]='#';

           } if(col-1>0 && board[row][col-1]=='O'){
            q.push({row,col-1});
            board[row][col-1]='#';

           }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O')board[i][j]='X';
                else if(board[i][j]=='#')board[i][j]='O';
            }
        }
        return ;
    }
};