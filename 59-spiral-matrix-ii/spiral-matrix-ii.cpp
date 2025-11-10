class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        int startRow=0;
        int endCol=n-1;
        int endRow=n-1;
        int startCol=0;
        int k=1;

        while(startRow<=endRow && startCol<=endCol){
            for(int j=startCol;j<=endCol;j++){
                ans[startRow][j]=k++;
            }
            startRow++;

            for(int i=startRow;i<=endRow;i++){
                ans[i][endCol]=k++;
            }
            endCol--;

            if(startRow<=endRow){
                for(int j=endCol;j>=startCol;j--){
                    ans[endRow][j]=k++;
                }
                endRow--;
            }
            
            if(startCol<=endCol){
                for(int i=endRow;i>=startRow;i--){
                    ans[i][startCol]=k++;

                }
                startCol++;
            }                
        }
        return ans;
    }
};