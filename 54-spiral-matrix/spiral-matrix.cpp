class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int startRow=0;
        int endCol=m-1;
        int endRow=n-1;
        int startCol=0;
        vector<int>ans;
        while(startRow<=endRow && startCol<=endCol){
            for(int j=startCol;j<=endCol;j++){
                ans.push_back(matrix[startRow][j]);
            }
            startRow++;

            for(int i=startRow;i<=endRow;i++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;

            if(startRow<=endRow){
                for(int j=endCol;j>=startCol;j--){
                    ans.push_back(matrix[endRow][j]);
                }
                endRow--;
            }
            
            if(startCol<=endCol){
                for(int i=endRow;i>=startRow;i--){
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }                
        }
        return ans;
    }
};